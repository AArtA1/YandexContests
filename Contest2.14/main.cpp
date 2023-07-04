#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

using std::cin, std::vector, std::cout, std::queue, std::unordered_map, std::string, std::to_string;

unordered_map<int, int> costs;
unordered_map<int, int> previous;

int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

class ComparatorClass {
public:
    // Comparator function
    bool operator()(const int a, const int b) {
        return costs[a] > costs[b];
    }
};

int getMinCost(int a, int b, int n) {
    std::priority_queue<int, vector<int>, ComparatorClass> q;
    q.push(a);
    previous[a] = -1;
    costs[a] = 0;

    while (!q.empty()) {
        int current = q.top();
        q.pop();

        if (current == b) {
            return costs[current];
        }

        string str_num = to_string(current);
        int len = str_num.length();

        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= len - i; j++) {
                int substr_num = stoi(str_num.substr(i, j));
                int cost = getDigitSum(substr_num);
                if (costs[current] + cost < n) {
                    if (costs.count(current + substr_num)) {
                        if (costs[current + substr_num] > costs[current] + cost) {
                            q.push(current + substr_num);
                            previous[current + substr_num] = current;
                        }
                        costs[current + substr_num] =
                            std::min(costs[current + substr_num], costs[current] + cost);
                    } else {
                        costs[current + substr_num] = costs[current] + cost;
                        previous[current + substr_num] = current;
                        q.push(current + substr_num);
                    }

                    if (costs.count(current - substr_num)) {
                        if (costs[current - substr_num] > costs[current] + cost) {
                            q.push(current - substr_num);
                            previous[current - substr_num] = current;
                        }
                        costs[current - substr_num] =
                            std::min(costs[current - substr_num], costs[current] + cost);
                    } else {
                        costs[current - substr_num] = costs[current] + cost;
                        previous[current - substr_num] = current;
                        q.push(current - substr_num);
                    }
                }

                /*if (substr_num > 0 && substr_num <= n && !costs.count(substr_num)) {
                    int cost = getDigitSum(substr_num);
                    costs[substr_num] = costs[current] + cost;
                    q.push(substr_num);
                }*/
            }
        }
    }

    return -1;  // Если достичь цели невозможно
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;

    cin >> n >> a >> b;

    int min_cost = getMinCost(a, b, n);

    if (min_cost == -1) {
        std::cout << -1;
    } else {
        std::stack<int> stack;
        int current = b;
        while (current != a) {
            int temp = previous[current];
            stack.push(current - temp);
            current = temp;
        }
        std::cout << min_cost << "\n" << stack.size() << "\n";
        while (!stack.empty()) {
            if (stack.top() > 0) {
                std::cout << "+" << stack.top() << "\n";
            } else {
                std::cout << stack.top() << "\n";
            }
            stack.pop();
        }
    }

    return 0;
}
