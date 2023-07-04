/*
//
// Created by aslan on 4/1/2023.
//
#include <iostream>
#include <set>
#include <stack>

using std::set, std::cin, std::cout;

struct Char {
    std::string code;
    char ch;
    Char() : code(nullptr), ch('\0') {
    }
    Char(std::string code, char ch) : code(code), ch(ch) {
    }
};

bool operator<(Char first, Char second) {
    return first.code.length() == second.code.length() ? first.code < second.code
                                                       : first.code.length() < second.code.length();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    set<Char> a;
    int number, length;
    std::string ch, code;
    cin >> number >> length;
    for (int i = 0; i < number; ++i) {
        cin >> ch >> code;
        a.insert(Char(code, ch[0]));
    }
    cin >> code;
    for (int i = 0; i < code.size();) {
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (code.substr(i, it->code.length()) == it->code) {
                cout << it->ch;
                i += it->code.length();
                break;
            }
        }
    }

    */
/*for(int i = code.size() - 1; i>=0;){
        for(auto it = a.begin(); it != a.end();++it){
            if(code.substr(i-it->code.length() + 1,it->code.length())==it->code){
                stack.push(it->ch);
                i-=it->code.length();
                break;
            }
        }
    }*//*

}*/
