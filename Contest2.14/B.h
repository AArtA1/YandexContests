/*
#include <iostream>
#include <vector>

using std::cin, std::vector, std::cout;

struct Edge {
    int64_t a, b;
    int64_t cost;
};

int64_t n, m, v;
vector<Edge> e;
const int64_t kInf = INT64_MAX;


// Алгоритм Беллмана-Форда (аналогично алгоритму дейкстры)
// Complexity: O(n^3) || O(n^2) - для разреженного графа
void solve() {
    vector<int64_t> d(n, kInf);
    d[v] = 0;
    vector<int64_t> p(n, -1);
    int64_t x;
    for (int64_t i = 0; i < n; ++i) {
        x = -1;
        for (int64_t j = 0; j < m; ++j) {
            if (d[e[j].a] < kInf) {
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = std::max(INT64_MIN, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }

    vector<int64_t> temp(d);

    for (int64_t i = 0; i < n + m; ++i) {
        for (int64_t j = 0; j < m; ++j) {
            if (d[e[j].a] < kInf) {
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = std::max(INT64_MIN, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }

    for (int64_t i = 0; i < n + m; ++i) {
        for (int64_t j = 0; j < m; ++j) {
            if (d[e[j].a] < kInf) {
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = std::max(INT64_MIN, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            }
        }
    }

    for (int64_t i = 0; i < n; ++i) {
        if (i == v) {
            continue;
        }
        if (temp[i] != d[i]) {
            std::cout << "-inf"
                      << "\n";
        } else {
            std::cout << d[i] << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    v = 0;
    int64_t a, b, cost;
    for (int64_t i = 0; i < m; ++i) {
        cin >> a >> b >> cost;
        e.push_back({a, b, cost});
    }
    solve();
}
*/
