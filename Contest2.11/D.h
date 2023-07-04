/*
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector, std::cin, std::cout;

int n;

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};

int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isPossible(int x, int y) {
    return !((x < 0) || (x >= n) || (y < 0) || (y >= n));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1;
    --x2;
    --y1;
    --y2;
    vector<vector<bool>> arr(n, vector<bool>(n, false));
    arr[x1][y1] = true;
    vector<vector<std::pair<int, int>>> parent(n, vector<std::pair<int, int>>(n));
    std::queue<std::pair<int, int>> q;
    q.push(std::pair(x1, y1));
    while (!q.empty() || !arr[x2][y2]) {
        auto last = q.front();
        q.pop();
        auto x = last.first;
        auto y = last.second;
        for (int i = 0; i < 8; ++i) {
            int tempx = x + dx[i], tempy = y + dy[i];
            if (isPossible(tempx, tempy) && !arr[tempx][tempy]) {
                arr[tempx][tempy] = true;
                parent[tempx][tempy] = std::pair(x, y);
                q.push(std::pair(tempx, tempy));
            }
        }
    }
    std::stack<std::pair<int, int>> stack;
    auto temp = std::pair(x2, y2);
    while (temp != std::pair(x1, y1)) {
        auto x = temp.first;
        auto y = temp.second;
        stack.push(temp);
        temp = parent[x][y];
    }
    std::cout << stack.size() << "\n";
    std::cout << x1 + 1 << " " << y1 + 1 << "\n";
    while (!stack.empty()) {
        auto val = stack.top();
        cout << val.first + 1 << " " << val.second + 1 << "\n";
        stack.pop();
    }
}
*/
