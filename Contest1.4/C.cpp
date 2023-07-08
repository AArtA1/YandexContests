#include <iostream>

using std::cout, std::cin;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i * i <= n; ++i) {
        for (int j = i; j * j <= n; ++j) {
            for (int k = j; k * k <= n; ++k) {
                for (int l = k; l * l <= n; ++l) {
                    if (i * i + j * j + k * k + l * l == n) {
                        cout << l;
                        if (j != 0) {
                            cout << " " << j;
                        }
                        if (k != 0) {
                            cout << " " << k;
                        }
                        if (i != 0) {
                            cout << " " << i;
                        }
                        return 0;
                    }
                }
            }
        }
    }
}
