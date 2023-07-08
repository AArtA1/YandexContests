#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cin, std::cout, std::vector;

/*void first(){
    int n;
    cin >> n;
    std::vector<int> array(n);
    std::vector<int> zeroes;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        if (array[i] == 0) {
            zeroes.push_back(i);
        }
    }
    cin >> n;
    int k, l;
    for (int i = 0; i < n; ++i) {
        cin >> k >> l;
        auto element = std::upper_bound(zeroes.begin(), zeroes.end(), k - 1.1);
        auto b = std::lower_bound(zeroes.begin(), zeroes.end(), l - 0.9);
        if (element == zeroes.end()) {
            cout << 0 << " ";
            continue;
        }
        int temp = distance(element, b);
        cout << temp << " ";
    }
}*/

std::multiset<int64_t> divide(int64_t element) {
    std::multiset<int64_t> dividers;
    int64_t i = 2;
    while (i * i <= element) {
        while (element % i == 0) {
            dividers.insert(i);
            element /= i;
        }
        ++i;
    }
    if (element != 1) {
        dividers.insert(element);
    }
    return dividers;
}

int main() {
    int64_t a, b, max = 1;
    cin >> a >> b;
    std::multiset<int64_t> dividers_a, dividers_b;
    if (a == b) {
        cout << a;
        return 0;
    }
    dividers_a = divide(a);
    dividers_b = divide(b);
    if (dividers_a.empty()) {
        if (dividers_b.empty()) {
            cout << 1;
            return 0;
        } else {
            cout << *--dividers_b.end();
            return 0;
        }
    }
    if (dividers_b.empty()) {
        cout << *--dividers_a.end();
        return 0;
    }
    std::vector<int64_t> first_diff;
    std::vector<int64_t> second_diff;
    std::set_difference(dividers_a.begin(), dividers_a.end(), dividers_b.begin(), dividers_b.end(),
                        std::back_inserter(first_diff));
    std::set_difference(dividers_b.begin(), dividers_b.end(), dividers_a.begin(), dividers_a.end(),
                        std::back_inserter(second_diff));
    if (first_diff.empty() || second_diff.empty()) {
        if (first_diff.empty()) {
            max = *--second_diff.end();
        }
        if (second_diff.empty()) {
            max = *--first_diff.end();
        }
    } else {
        auto first_max = *--first_diff.end();
        auto second_max = *--second_diff.end();
        if (first_max > second_max) {
            max = first_max;
        } else {
            max = second_max;
        }
    }
    std::vector<int64_t> v_intersection;
    std::set_intersection(dividers_a.begin(), dividers_a.end(), dividers_b.begin(),
                          dividers_b.end(), std::back_inserter(v_intersection));
    int64_t result = 1;
    for (auto i : v_intersection) {
        result *= i;
    }
    result *= max;
    cout << result;
}
