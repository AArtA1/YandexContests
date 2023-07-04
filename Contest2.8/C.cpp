/*
//
// Created by aslan on 4/1/2023.
// Кодирование Хэмминга
#include <iostream>
#include <vector>
#include <cmath>

// Функция возвращает код Хэмминга для заданного сообщения
std::vector<int> hammingCode(const std::vector<int>& message) {
    // Вычисляем количество проверочных битов
    int r = 0;
    while (pow(2, r) < message.size() + r + 1) {
        r++;
    }
    // Вычисляем размер кодового слова
    int n = message.size() + r;
    // Создаем кодовое слово и заполняем его нулями
    std::vector<int> code(n, 0);
    // Заполняем кодовое слово значениями из сообщения
    for (int i = 0, j = 0; i < n; i++) {
        // Если i+1 - степень двойки, то это проверочный бит, пропускаем его
        if ((i & (i + 1)) == 0) {
            continue;
        }
        // Иначе это бит из сообщения
        code[i] = message[j++];
    }
    // Вычисляем значения проверочных битов
    for (int i = 0; i < r; i++) {
        int bit_pos = pow(2, i) - 1;
        int sum = 0;
        for (int j = bit_pos; j < n; j += 2 * bit_pos + 2) {
            for (int k = j; k < j + bit_pos + 1 && k < n; k++) {
                sum += code[k];
            }
        }
        code[bit_pos] = sum % 2;
    }
    return code;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::cin >> str;
    std::vector<int> message(str.length());
    for (int i = 0; i < str.length(); ++i) {
        message[i] = str[i] == '1' ? 1 : 0;
    }
    auto result = hammingCode(message);
    for (auto i : result) {
        std::cout << i;
    }
}*/
