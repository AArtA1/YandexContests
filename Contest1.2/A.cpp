#include <iterator>
#include <initializer_list>
#include <iostream>
#include <vector>

class Vector {
public:
    struct Iterator {
        using IteratorCategory = std::random_access_iterator_tag;
        using DifferenceType = std::ptrdiff_t;

        explicit Iterator(int* ptr) : m_ptr_(ptr){};

        int& operator*() const {
            return *m_ptr_;
        }
        int* operator->() {
            return m_ptr_;
        }

        Iterator& operator++() {
            ++m_ptr_;
            return *this;
        }
        Iterator operator++(int) {
            return Iterator(m_ptr_++);
        }

        Iterator& operator--() {
            --m_ptr_;
            return *this;
        }
        Iterator operator--(int) {
            return Iterator(m_ptr_--);
        }

        Iterator operator+(const DifferenceType& movement) {
            return Iterator(m_ptr_ + movement);
        }
        Iterator operator-(const DifferenceType& movement) {
            return Iterator(m_ptr_ - movement);
        }

        Iterator& operator+=(const DifferenceType& movement) {
            m_ptr_ += movement;
            return *this;
        }
        Iterator& operator-=(const DifferenceType& movement) {
            m_ptr_ -= movement;
            return *this;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.m_ptr_ == b.m_ptr_;
        }
        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.m_ptr_ != b.m_ptr_;
        }

    private:
        int* m_ptr_;
    };

    Vector() {
        arr_ = new int[capacity_];
    }

    explicit Vector(size_t n_size) {
        size_ = n_size;
        capacity_ = n_size * 2;
        arr_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = 0;
        }
    }

    Vector(const int* vals, size_t size) {
        size_ = size;
        capacity_ = size_ * 2;
        arr_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = vals[i];
        }
    }

    Vector(const Vector& vec) {
        size_ = vec.size_;
        capacity_ = vec.capacity_;
        arr_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = vec[i];
        }
    }

    Vector(std::initializer_list<int> vals) {
        size_ = vals.size();
        capacity_ = size_ * 2;
        arr_ = new int[capacity_];
        int i = 0;
        for (auto j : vals) {
            arr_[i] = j;
            ++i;
        }
    }

    ~Vector() {
        delete[] arr_;
    }

    size_t getSize() const {
        return size_;
    }

    size_t getCapacity() const {
        return capacity_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    void resize(size_t n_size) {
        int* temp = new int[n_size >= capacity_ ? capacity_ = n_size * 2 : n_size];
        if (n_size > size_) {
            for (int i = 0; i < size_; ++i) {
                temp[i] = arr_[i];
            }
            for (int i = size_; i < n_size; ++i) {
                temp[i] = 0;
            }
        } else {
            for (int i = 0; i < n_size; ++i) {
                temp[i] = arr_[i];
            }
        }
        delete[] arr_;
        arr_ = temp;
        size_ = n_size;
    }

    void pushBack(int value) {
        if (size_ == capacity_) {
            resize(size_);
            arr_[size_] = value;
            ++size_;
        } else {
            arr_[size_] = value;
            ++size_;
        }
    }

    void popBack() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        } else {
            --size_;
        }
    }

    void clear() {
        size_ = 0;
    }

    void insert(size_t pos, int value) {
        if (pos > size_) {
            throw std::runtime_error("Wrong Position!");
        } else {
            int* temp = new int[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                temp[i] = arr_[i];
            }
            if (size_ >= capacity_) {
                delete[] arr_;
                arr_ = new int[capacity_ * 2];
                ++size_;
                for (size_t i = 0; i < pos; ++i) {
                    arr_[i] = temp[i];
                }
                arr_[pos] = value;
                for (size_t i = pos + 1; i < size_; ++i) {
                    arr_[i] = temp[i - 1];
                }
            } else {
                for (size_t i = 0; i < pos; ++i) {
                    arr_[i] = temp[i];
                }
                arr_[pos] = value;
                ++size_;
                for (size_t i = pos + 1; i < size_; ++i) {
                    arr_[i] = temp[i - 1];
                }
            }
            delete[] temp;
        }
    }

    void erase(size_t pos) {
        if (isEmpty()) {
            throw std::runtime_error("Empty Array!");
        } else if (pos < 0 || pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }

        for (int i = pos; i < size_ - 1; ++i) {
            arr_[i] = arr_[i + 1];
        }
        --size_;
    }

    int at(int pos) {
        if (pos >= size_ || pos < 0) {
            throw std::runtime_error("Wrong Position!");
        }
        return arr_[pos];
    }

    int front() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return arr_[0];
    }

    int back() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return arr_[size_ - 1];
    }

    Iterator begin() {
        return Iterator(arr_);
    }

    Iterator end() {
        return Iterator(arr_ + size_);
    }

    int& operator[](size_t pos) const {
        if (static_cast<int>(pos) >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        return arr_[pos];
    }

    Vector& operator=(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        int* temp = new int[other.capacity_];
        for (size_t i = 0; i < other.size_; ++i) {
            temp[i] = other[i];
        }
        delete[] arr_;
        arr_ = temp;
        return *this;
    }

private:
    int capacity_ = 10, size_ = 0, *arr_;
};

void insertionSort(Vector::Iterator begin, Vector::Iterator end) {
    for (auto i = begin; i != end; ++i) {
        for (auto j = i + 1; j != end; ++j) {
            if (*i > *j) {
                std::swap(*i, *j);
            }
        }
    }
}

void mergeSort(Vector& vec) {
    int left, right, mid, end, now;
    Vector temp = vec;

    for (int width = 1; width < vec.getSize(); width *= 2) {
        for (int start = 0; start < vec.getSize(); start += 2 * width) {
            mid = start + width - 1;
            end = start + 2 * width - 1;

            if (mid >= vec.getSize()) {
                mid = vec.getSize() - 1;
            }
            if (end >= vec.getSize()) {
                end = vec.getSize() - 1;
            }
            left = start;
            right = mid + 1;
            now = start;

            while (left <= mid && right <= end) {
                if (vec.at(left) <= vec.at(right)) {
                    temp[now] = vec[left];
                    left++;
                } else {
                    temp[now] = vec[right];
                    right++;
                }
                now++;
            }
            while (left <= mid) {
                temp[now] = vec[left];
                left++;
                now++;
            }
            while (right <= end) {
                temp[now] = vec[right];
                right++;
                now++;
            }
        }
        vec = temp;
    }
}

void mergeSort(Vector::Iterator begin, Vector::Iterator end) {
    Vector vec;
    for (auto i = begin; i != end; ++i) {
        vec.pushBack(*i);
    }
    mergeSort(vec);
    int c = 0;
    for (auto i = begin; i != end; ++i) {
        *i = vec[c];
        ++c;
    }
}
/*
int main() {
    Vector vec({1})
    vec.insert(1, 2);
    vec.insert(2, 3);
    for (auto i : vec) {
        std::cout << i;
    }
}*/
