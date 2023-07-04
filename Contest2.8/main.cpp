#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using std::cin, std::cout, std::vector, std::queue;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    std::string str;
    cin >> str;
    /*vector<bool> array(str.length());
    for(int i = 0; i < array.size();++i){
        array[i] = str[i] == '1';
    }*/
    int r = log2(str.size()) + 1;
    int n = str.size();
    queue<bool> bytes;
    for (int i = 0; i < r; i++) {
        int bit_pos = pow(2, i) - 1;
        int sum = 0;
        for (int j = bit_pos; j < n; j += 2 * bit_pos + 2) {
            for (int k = j; k < j + bit_pos + 1 && k < n; k++) {
                sum += str[k] == '1' ? 1 : 0;
            }
        }
        bytes.push(sum % 2);
    }
    int pow2 = 1;
    int sum = 0;
    while (!bytes.empty()) {
        bool value = bytes.front();
        sum += value ? pow2 : 0;
        pow2 *= 2;
        bytes.pop();
    }
    if (!(sum == 0 || sum > str.length())) {
        str[sum - 1] = str[sum - 1] == '1' ? '0' : '1';
    }
    for (int i = 0; i < str.size(); ++i) {
        if ((i & (i + 1)) == 0) {
            continue;
        } else {
            cout << str[i];
        }
    }
}