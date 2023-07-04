#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout;

vector<int> prefixFunction(std::string s) {
    vector<int> array(s.length());
    array[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        int k = array[i - 1];
    while (k > 0 && s[i] != s[k]) {
            k = array[k - 1];
        }
        if (s[i] == s[k]) {
            ++k;
        }
        array[i] = k;
    }
    return array;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    std::string str;
    cin >> str;
    auto result = prefixFunction(str);
    for (auto i : result) {
        cout << i << " ";
    }
}