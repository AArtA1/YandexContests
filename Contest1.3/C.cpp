#include <iostream>
#include <stack>
#include <map>

int main() {
    std::string str;
    std::cin >> str;
    bool flag = true;
    std::stack<char> stack{};
    std::map<char, char> symbols{{'}', '{'}, {')', '('}, {']', '['}};
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            stack.push(str[i]);
        } else {
            if (stack.top() != symbols[str[i]]) {
                flag = false;
                break;
            } else {
                stack.pop();
            }
        }
    }
    flag &&stack.empty() ? std::cout << "YES" : std::cout << "NO";
}