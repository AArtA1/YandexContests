#include <iostream>
#include <algorithm>
#include <vector>

using std::cin, std::vector, std::cout;

const int kN = 15e4 + 7, kM = 1e9 + 7;
vector<int> cage[kN];
vector<int> par(kN), sz(kN);
int n;

int findLeader(int u) {
    if (par[u] == u) {
        return u;
    }
    return par[u] = findLeader(par[u]);
}
void connectNodes(int u, int v) {
    u = findLeader(u);
    v = findLeader(v);

    if (u == v) {
        return;
    }
    if (sz[u] < sz[v]) {
        par[u] = v;
        sz[v] += sz[u];
        for (auto i : cage[u]) {
            cage[v].push_back(i);
        }
        cage[u].clear();
    } else {
        par[v] = u;
        sz[u] += sz[v];
        for (auto i : cage[v]) {
            cage[u].push_back(i);
        }
        cage[v].clear();
    }
}
int main(void) {
    cin >> n;
    int u, v;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        cage[i].push_back(i);
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        connectNodes(u, v);
    }
    int leader = findLeader(1);
    for (auto i : cage[leader]) {
        cout << i << ' ';
    }
}