#include <iostream>
#include <cstddef>
#include <math.h>

class Node {
public:
    int data{};
    Node* next;
    Node* previous;

    Node() : next(nullptr), previous(nullptr) {
    }
    Node(int data) : data(data), next(nullptr), previous(nullptr) {
    }
};

class List {
public:
    List() : head(nullptr), tail(nullptr) {
    }
    List(int* values, size_t size) {
        for (int i = 0; i < size; ++i) {
            if (abs(values[i]) > 2 * pow(10, 9)) {
                clear();
                throw std::runtime_error("Wrong Value!");
            } else {
                pushBack(values[i]);
            }
        }
    }

    ~List() {
        clear();
    }

    void pushBack(int value) {
        if (abs(value) > 2 * pow(10, 9)) {
            throw std::runtime_error("Wrong Value!");
        }
        if (head == nullptr) {
            head = tail = new Node(value);
            head->previous = tail;
            tail->next = head;
            return;
        }
        if (head == tail) {
            tail = new Node(value);
            tail->next = head;
            tail->previous = head;
            head->next = tail;
            head->previous = tail;
            return;
        }
        Node* temp = tail;
        tail = new Node(value);
        temp->next = tail;
        tail->previous = temp;
        tail->next = head;
        head->previous = tail;
    }
    void pushFront(int value) {
        if (abs(value) > 2 * pow(10, 9)) {
            throw std::runtime_error("Wrong Value!");
        }
        if (head == nullptr) {
            head = tail = new Node(value);
            head->previous = tail;
            tail->next = head;
            return;
        }
        if (head == tail) {
            head = new Node(value);
            head->next = tail;
            head->previous = tail;
            tail->previous = head;
            tail->next = head;
            return;
        }
        Node* temp = head;
        head = new Node(value);
        head->next = temp;
        head->previous = tail;
        temp->previous = head;
        tail->next = head;
    }
    int pop() {
        if (head == nullptr) {
            throw std::runtime_error("Can not pop such element!");
        }
        if (head == tail) {
            int value = head->data;
            delete head;
            head = tail = nullptr;
            return value;
        }
        if (getSize() == 2) {
            int value = head->data;
            delete head;
            head = tail;
            head->previous = tail;
            tail->next = head;
            return value;
        }
        int value = head->data;
        Node* tmp = head;
        head = head->next;
        head->previous = tail;
        tail->next = head;
        delete tmp;
        return value;
    }

    int pop(int position) {
        auto size = getSize();
        if (position <= size - 2 && position >= 0) {
            if (size == 2) {
                int value = tail->data;
                delete tail;
                tail = head;
                head->previous = tail;
                tail->next = head;
                return value;
            }
            if (position == size - 2) {
                int value = tail->data;
                Node* temp = tail;
                tail = tail->previous;
                tail->next = head;
                head->previous = tail;
                delete temp;
                return value;
            }
            int i = 0;
            Node* current = head;
            while (i != position) {
                current = current->next;
                ++i;
            }
            int value = current->next->data;
            Node* temp = current->next->next;
            delete current->next;
            current->next = temp;
            temp->previous = current;
            return value;
        } else {
            throw std::runtime_error("Wrong Position!");
        }
    }

    void push(int value, int position) {
        auto size = getSize();
        if (position <= size - 1 && position >= 0) {
            if (abs(value) > 2 * pow(10, 9)) {
                throw std::runtime_error("Wrong Value!");
            }
            if (position == size - 1) {
                pushBack(value);
                return;
            }
            int i = 0;
            Node* current = head;
            while (i != position) {
                current = current->next;
                ++i;
            }
            Node* temp = new Node(value);
            temp->next = current->next;
            current->next->previous = temp;
            temp->previous = current;
            current->next = temp;
        } else {
            throw std::runtime_error("Wrong Position!");
        }
    }
    int getSize() {
        if (head == nullptr) {
            return 0;
        }
        if (head == tail) {
            return 1;
        }
        Node* current = head;
        int i = 1;
        while (current != tail) {
            current = current->next;
            ++i;
        }
        return i;
    }
    void print() {
        if (head == nullptr) {
            return;
        }
        Node* p = head;
        while (p != tail) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << tail->data;
        std::cout << std::endl;
    }
    void clear() {
        auto size = getSize();
        if (size == 0) {
            return;
        }
        if (size == 1) {
            delete head;
            return;
        }
        if (size == 2) {
            delete head;
            delete tail;
            return;
        }
        Node* current = head;
        for (int i = 0; i < size - 1; ++i) {
            delete current->previous;
            if (i == size - 2) {
                continue;
            } else {
                current = current->next;
            }
        }
        delete current;
    }
    Node* head{};
    Node* tail{};
};
/*
int main() {
    int* arr = new int[0];
    for (int i = 0; i < 0; ++i) {
        arr[i] = i + 1;
    }
    List list;
    list.pop(2);
    list.print();
}*/
