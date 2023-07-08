#include <iostream>
#include <vector>
#include <algorithm>

class Stack {
public:
    void push(int value) {
        stack_.push_back(value);
    }

    int pop() {
        if (!stack_.empty()) {
            int i = stack_.back();
            stack_.pop_back();
            return i;
        } else {
            throw std::runtime_error("error");
        }
    }
    int back() const {
        if (!stack_.empty()) {
            return stack_.back();
        } else {
            throw std::runtime_error("error");
        }
    }

    size_t size() const {
        return stack_.size();
    }

    void clear() {
        stack_.clear();
    }

private:
    std::vector<int> stack_;
};