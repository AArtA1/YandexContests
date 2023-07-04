#include <vector>
#include <iostream>
#include <algorithm>

using std::cin, std::cout, std::pair, std::vector;


// Поиск минимального остовного дерева8
int getCost(const vector<pair<int, pair<int, int>>>& g, int n, int m, int k,
            vector<pair<int, int>>& result) {
    int total_weight = 0;
    vector<int> tree_id(n);
    for (int i = 0; i < n; ++i) {
        tree_id[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (i == k) {
            continue;
        }
        int a = g[i].second.first;
        int b = g[i].second.second;
        int temp_weight = g[i].first;
        if (tree_id[a] != tree_id[b]) {
            total_weight += temp_weight;
            result.push_back(std::make_pair(a, b));
            int old_id = tree_id[b], new_id = tree_id[a];
            for (int j = 0; j < n; ++j) {
                if (tree_id[j] == old_id) {
                    tree_id[j] = new_id;
                }
            }
        }
    }
    return total_weight;
}

int main() {
    int n, m, weight, first, second;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> g(m);
    for (int i = 0; i < m; ++i) {
        cin >> first >> second >> weight;
        --first;
        --second;
        g[i] = std::make_pair(weight, std::make_pair(first, second));
    }

    int total_weight = 0;
    vector<pair<int, int>> result;
    sort(g.begin(), g.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        return a.first < b.first;
    });
    auto min = getCost(g, n, m, -1, result);
    // std::sort(result.begin(), result.end());
    auto second_min = INT32_MAX;
    vector<pair<int, int>> temp_arr;
    for (int i = 0; i < m; ++i) {
        auto temp = getCost(g, n, m, i, temp_arr);
        if (temp == min) {
            // std::sort(temp_arr.begin(), temp_arr.end());
            if (result != temp_arr) {
                second_min = temp;
                break;
            }
        } else {
            second_min = temp < second_min ? temp : second_min;
        }
        temp_arr.clear();
    }
    std::cout << min << " " << second_min;
}