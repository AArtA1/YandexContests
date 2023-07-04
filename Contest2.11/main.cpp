#include <iostream>
#include <vector>
#include <forward_list>
#include <queue>
#include <set>
#include <algorithm>
#include <list>

using std::vector, std::cin, std::cout, std::string;

vector<string> names;
vector<bool> distance;

class Graph {
public:
    vector<vector<int>> nodes_;
    Graph() = default;
    Graph(int n) : nodes_(n) {
    }
    void add(int source, int destination) {
        nodes_[source].push_back(destination);
        nodes_[destination].push_back(source);
    }
    void sort() {
        for (int i = 0; i < nodes_.size(); ++i) {
            std::sort(nodes_[i].begin(), nodes_[i].end(),
                      [](int first, int second) { return names[first] < names[second]; });
        }
    }
};

struct Node {
    string name;
    int index;
    Node() = default;
    Node(string name, int index) : name(name), index(index) {
    }
};

bool operator<(const Node& first, const Node& second) {
    return first.name < second.name;
}

Graph graph;
std::list<string> list;
int n, counter;

void getNodes(int u) {
    int temp = 0;
    while (temp < graph.nodes_[u].size()) {
        auto value = graph.nodes_[u][temp];
        if (!distance[value]) {
            list.push_back(names[value]);
            distance[value] = true;
            ++counter;
            getNodes(value);
        }
        ++temp;
        if (counter == n) {
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int edges, temp, src, dest;
    string str;
    cin >> n >> edges;
    names = vector<string>(n);
    distance = vector<bool>(n, false);
    graph = Graph(n);
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        getline(cin, str);
        names[i] = str;
    }
    for (int i = 0; i < edges; ++i) {
        cin >> src >> dest;
        graph.add(src, dest);
    }
    graph.sort();
    cin >> temp;
    counter = 0;
    distance[temp] = true;
    getNodes(temp);
    std::cout << names[temp] << "\n";
    for (auto item : list) {
        cout << item << "\n";
    }
}