#include <iostream>
#include <deque>

class Deque {
public:
    void pushBack(int value) {
        deque_.push_back(value);
    }

    void pushMiddle(int value) {
        if (deque_.size() % 2 == 0) {
            deque_.insert(deque_.begin() + deque_.size() / 2, value);
        } else {
            deque_.insert(deque_.begin() + deque_.size() / 2 + 1, value);
        }
    }

    int popFront() {
        int i = deque_.front();
        deque_.pop_front();
        return i;
    }

    int front() const {
        return deque_.front();
    }

    int back() const {
        return deque_.back();
    }

    size_t size() const {
        return deque_.size();
    }

private:
    std::deque<int> deque_;
};