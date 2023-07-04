#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>


using std::cin,std::vector,std::cout,std::queue,std::unordered_map,std::string,std::to_string;


int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int getMinCost(int a, int b, int n) {
    queue<int> q;
    q.push(a);
    unordered_map<int, int> costs;
    costs[a] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == b) {
            return costs[current];
        }

        string str_num = to_string(current);
        int len = str_num.length();

        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= len - i; j++) {
                int substr_num = stoi(str_num.substr(i, j));

                if (substr_num > 0 && substr_num <= n && !costs.count(substr_num)) {
                    int cost = getDigitSum(substr_num);
                    costs[substr_num] = costs[current] + cost;
                    q.push(substr_num);
                }
            }
        }
    }

    return -1;  // Если достичь цели невозможно
}

int main() {
    int n,a,b;

    cin >> n >> a >> b;

    int min_cost = getMinCost(a, b, n);



    if (min_cost != -1) {
        //cout << "Минимальная стоимость: " << min_cost << endl;
    } else {
        //cout << "Невозможно достичь цели" << endl;
    }

    return 0;
}
