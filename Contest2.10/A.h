#include <iostream>
#include <unordered_map>
#include <string>

using std::unordered_map, std::cout, std::cin, std::string, std::to_string;

// Функция для кодирования строки с использованием алгоритма LZW
string lzwEncoding(const string &input, int &counter) {
    unordered_map<string, int> dictionary;
    for (int i = 0; i < 128; i++) {
        string c(1, static_cast<char>(i));
        dictionary[c] = i;
    }

    string current;
    string result;
    for (char c : input) {
        string next = current + c;
        if (dictionary.find(next) != dictionary.end()) {
            current = next;
        } else {
            ++counter;
            result += to_string(dictionary[current]) + " ";
            dictionary[next] = dictionary.size();
            current = string(1, c);
        }
    }

    if (!current.empty()) {
        result += to_string(dictionary[current]);
    }

    return result;
}

int main() {
    string input;
    std::getline(cin, input);
    int counter = 1;
    string encoded = lzwEncoding(input, counter);
    cout << counter << "\n" << encoded;
    return 0;
}
