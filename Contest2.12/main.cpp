#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

void dfs(const int& v, const bool& for_reversed, const int& c, const vector<vector<int>>& g,
         const vector<vector<int>>& gr, vector<int>& order, vector<int>& component,
         vector<bool>& used) {
    used[v] = true;
    if (for_reversed) {
        component[v] = c;
        for (const auto& to : gr[v]) {
            if (!used[to]) {
                dfs(to, for_reversed, c, g, gr, order, component, used);
            }
        }
    } else {
        for (const auto& to : g[v]) {
            if (!used[to]) {
                dfs(to, for_reversed, c, g, gr, order, component, used);
            }
        }
        order.push_back(v);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int count, quantity;
    std::cin >> count >> quantity;
    vector<vector<int>> g(count), gr(count);
    vector<bool> used(count, false);
    vector<int> order, component(count);
    for (int i = 0; i < quantity; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    for (int i = 0; i < count; ++i) {
        if (!used[i]) {
            dfs(i, false, 0, g, gr, order, component, used);
        }
    }
    int components_quantity = 0;
    used = vector<bool>(count, false);
    for (int i = 0; i < count; ++i) {
        int v = order[count - i - 1];
        if (!used[v]) {
            dfs(v, true, components_quantity, g, gr, order, component, used);
            ++components_quantity;
        }
    }
    cout << components_quantity << "\n";
    for (const auto& v : component) {
        cout << v + 1 << " ";
    }
}