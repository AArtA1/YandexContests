/*
#include <iostream>
#include <vector>
#include <queue>

using std::cin, std::cout;

// Структура для представления ребра графа
struct Edge {
    int destination;
    int64_t weight;
};


// Алгоритм дейкстры для поиска минимального пути в неотрицательном ориентированном графе
// Complexity O(n^2+m)
void dijkstra(const std::vector<std::vector<Edge>> &graph, int start_node,
              std::vector<int64_t> &distances) {
    distances[start_node] = 0;  // Расстояние от начальной вершины до неё самой равно 0

    // Приоритетная очередь, в которой будем хранить вершины в порядке возрастания их расстояний
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    pq.push(std::make_pair(0, start_node));  // Добавляем начальную вершину в очередь

    while (!pq.empty()) {
        int current_node = pq.top().second;  // Извлекаем вершину с наименьшим расстоянием
        pq.pop();

        // Перебираем соседние вершины
        for (const auto &edge : graph[current_node]) {
            int64_t new_distance = distances[current_node] + edge.weight;
            if (new_distance < distances[edge.destination]) {
                distances[edge.destination] = new_distance;
                pq.push(std::make_pair(new_distance, edge.destination));
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num_nodes, quantity, src, dest;
    int64_t weight;
    std::cin >> quantity >> num_nodes;
    std::vector<std::vector<Edge>> graph(quantity);
    for (int i = 0; i < num_nodes; ++i) {
        std::cin >> src >> dest >> weight;
        graph[src].push_back(Edge{dest, weight});
    }
    std::vector<int64_t> distances(quantity, INT64_MAX);

    int start_node = 0;
    dijkstra(graph, start_node, distances);

    for (int i = 1; i < quantity; ++i) {
        cout << distances[i] << "\n";
    }

    */
/*for (int i = 0; i < numNodes; ++i) {
        if(i != startNode){
            cout << distances[i] << "\n";
        }
    }*//*

}
*/
