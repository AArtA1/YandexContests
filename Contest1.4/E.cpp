#include <iostream>
#include <vector>
#include <iomanip>

using std::vector, std::cout, std::cin;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vector_1(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vector_1[i][j];
        }
    }
    vector<int> temp(2 * m);
    int c = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto it1 = vector_1[i].begin();
            auto it2 = vector_1[j].begin();
            while (it1 != vector_1[i].end() || it2 != vector_1[j].end()) {
                if (it1 != vector_1[i].end() && it2 != vector_1[j].end()) {
                    if (*it1 > *it2) {
                        temp[c++] = *it2;
                        ++it2;
                    } else {
                        temp[c++] = *it1;
                        ++it1;
                    }
                    continue;
                }
                if (it1 != vector_1[i].end()) {
                    temp[c++] = *it1;
                    ++it1;
                    continue;
                }
                if (it2 != vector_1[j].end()) {
                    temp[c++] = *it2;
                    ++it2;
                    continue;
                }
            }
            size_t size = temp.size();
            double value = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
            cout << std::fixed << std::setprecision(5) << value << "\n";
            temp.clear();
            temp = vector<int>(2 * m);
            c = 0;
        }
    }
}
