//
// Created by aslan on 4/12/2023.
// LZW encoding
/*
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using std::cout, std::cin, std::vector, std::string;

void lzwDecoding(vector<int> output_code) {
    std::unordered_map<int, string> table;
    for (int i = 0; i < 128; i++) {
        string str;
        char ch = i;
        str += ch;
        table[i] = str;
    }
    int old_code = output_code[0];
    int n;
    string str1 = table[old_code];
    string str2;
    str2 += str1[0];
    cout << str1;
    int count = 128;
    for (int i = 0; i < output_code.size() - 1; i++) {
        n = output_code[i + 1];
        if (table.find(n) == table.end()) {
            str1 = table[old_code];
            str1 = str1 + str2;
        } else {
            str1 = table[n];
        }
        cout << str1;
        str2 = "";
        str2 += str1[0];
        table[count] = table[old_code] + str2;
        count++;
        old_code = n;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    lzwDecoding(array);
}
*/