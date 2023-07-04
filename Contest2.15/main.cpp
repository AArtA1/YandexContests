#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector, std::numeric_limits, std::queue, std::min, std::cin, std::cout, std::endl;

// Структура, представляющая ребро в графе
struct Edge {
    int from, to, capacity, flow;
};

// Функция для добавления ребра в граф
void addEdge(vector<vector<int>>& graph, vector<Edge>& edges, int from, int to, int capacity) {
    graph[from].push_back(edges.size());
    edges.push_back({from, to, capacity, 0});
    graph[to].push_back(edges.size());
    edges.push_back({to, from, 0, 0});
}

// Функция для поиска максимального потока в графе
int findMaxFlow(vector<vector<int>>& graph, vector<Edge>& edges, int source, int sink) {
    int n = graph.size();
    vector<int> parent(n);
    int max_flow = 0;

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        vector<int> min_capacity(n, numeric_limits<int>::max());

        queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int edge_idx : graph[u]) {
                Edge& edge = edges[edge_idx];
                if (parent[edge.to] == -1 && edge.capacity > edge.flow) {
                    parent[edge.to] = edge_idx;
                    min_capacity[edge.to] = min(min_capacity[u], edge.capacity - edge.flow);
                    if (edge.to == sink) {
                        max_flow += min_capacity[sink];
                        int v = sink;
                        while (v != source) {
                            edge_idx = parent[v];
                            edges[edge_idx].flow += min_capacity[sink];
                            edges[edge_idx ^ 1].flow -= min_capacity[sink];
                            v = edges[edge_idx].from;
                        }
                        break;
                    }
                    q.push(edge.to);
                }
            }
        }

        if (parent[sink] == -1) {
            break;
        }
    }

    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        addEdge(graph, edges, from - 1, to - 1, capacity);
    }
    int source = 0;    // Вершина 1
    int sink = n - 1;  // Вершина n
    int max_flow = findMaxFlow(graph, edges, source, sink);
    cout << max_flow << endl;

    return 0;
}
