#include <iostream>
#include <vector>
#include <algorithm>

using std::cin, std::cout, std::vector;

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    std::vector<int> zeroes;
    for (auto i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] == 0) {
            zeroes.push_back(i);
        }
    }
    cin >> n;
    int k, l;
    for (int i = 0; i < n; ++i) {
        cin >> k >> l;
        auto a = std::upper_bound(zeroes.begin(), zeroes.end(), k - 1.1);
        auto b = std::lower_bound(zeroes.begin(), zeroes.end(), l - 0.9);
        if (a == zeroes.end()) {
            cout << 0 << " ";
            continue;
        }
        int temp = distance(a, b);
        cout << temp << " ";
    }
}
