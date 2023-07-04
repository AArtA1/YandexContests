/*
#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

const int64_t kMax = 1000000000000000;

// Алгоритм Флойда-Уоршелла для поиска минимального пути неотрицательного ориентированного графа
// ребер Complexity: O(n^3)
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int64_t n, m;
    cin >> n >> m;
    int64_t a, b, cost;
    vector<vector<int64_t>> matrix(n, vector<int64_t>(n, kMax));
    for (int64_t i = 0; i < m; ++i) {
        cin >> a >> b >> cost;
        matrix[a][b] = cost;
    }
    for (int64_t i = 0; i < n; ++i) {
        matrix[i][i] = 0;
    }
    for (int64_t k = 0; k < n; ++k) {
        for (int64_t i = 0; i < n; ++i) {
            for (int64_t j = 0; j < n; ++j) {
                matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            } else {
                if (matrix[i][j] == kMax) {
                    cout << i << " " << j << " " << -1 << "\n";
                } else {
                    cout << i << " " << j << " " << matrix[i][j] << "\n";
                }
            }
        }
    }
}*/
