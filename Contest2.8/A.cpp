//
// Created by aslan on 4/1/2023.
// Кодирование Хаффмана

/*
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using std::cin, std::cout, std::string, std::priority_queue, std::unordered_map, std::vector,
    std::sort;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

void destroyTree(Node *root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

Node *make(char ch, int freq, Node *left, Node *right) {
    Node *node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

struct Comp {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void encode(Node *root, string str, unordered_map<char, string> &huffman_code) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        huffman_code[root->ch] = str;
    }

    encode(root->left, str + "0", huffman_code);
    encode(root->right, str + "1", huffman_code);
}

void decode(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }

    // found a leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] =='0'){
        decode(root->left, index, str);
    }
    else{
        decode(root->right, index, str);
    }
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> frequency{};
    for (char ch : text) {
        ++frequency[ch];
    }
    priority_queue<Node *, vector<Node *>, Comp> queue{};

    for (auto pair : frequency) {
        queue.push(make(pair.first, pair.second, nullptr, nullptr));
    }

    while (queue.size() != 1) {
        Node *left = queue.top();
        queue.pop();
        Node *right = queue.top();
        queue.pop();
        int sum = left->freq + right->freq;
        queue.push(make('\0', sum, left, right));
    }
    Node *root = queue.top();
    if (root->ch != '\0') {
        cout << 1 << " " << text.size() << "\n";
        cout << root->ch << ": 0\n";
        for (size_t i = 0; i < text.size(); ++i) {
            cout << 0;
        }
        destroyTree(root);
        return;
    }
    unordered_map<char, string> huffman_code;
    encode(root, "", huffman_code);

    vector<std::pair<char, string>> array(huffman_code.size());
    int i = 0;
    int count = 0;
    for (auto pair : huffman_code) {
        array[i] = pair;
        count += frequency[pair.first] * pair.second.size();
        ++i;
    }
    cout << huffman_code.size() << " " << count << "\n";
    sort(array.begin(), array.end(),
         [](std::pair<char, string> first, std::pair<char, string> second) {
             return first.second < second.second;
         });
    for (auto value = array.begin(); value != array.end(); ++value) {
        cout << value->first << ": " << value->second << "\n";
    }

    string str{};
    for (char ch : text) {
        str += huffman_code[ch];
    }

    cout << str;
    destroyTree(root);
}

int main() {
    int n, length,number;
    string str;
    cin >> n >> length;
    unordered_map<char,int> frequency{};
    for(int i = 0; i < n;++i){
        cin >> str >> number;
        frequency[str[0]] = number;
    }
    cin >> str;
    priority_queue<Node *, vector<Node *>, Comp> queue{};
    for (auto pair : frequency) {
        queue.push(make(pair.first, pair.second, nullptr, nullptr));
    }

    while (queue.size() != 1) {
        Node *left = queue.top();
        queue.pop();
        Node *right = queue.top();
        queue.pop();
        int sum = left->freq + right->freq;
        queue.push(make('\0', sum, left, right));
    }
    Node* root = queue.top();
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < static_cast<int>(str.size()) - 2) {
        decode(root, index, str);
    }
}*/
