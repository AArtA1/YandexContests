#include <queue>
#include <set>

class Queue {
public:
    void push(int value) {
        queue_.push(value);
        set_.insert(value);
    }

    int pop() {
        int i = queue_.front();
        set_.erase(i);
        queue_.pop();
        return i;
    }

    int min() const {
        return *set_.begin();
    }

private:
    std::queue<int> queue_;
    std::multiset<int> set_;
};