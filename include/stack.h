#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
class Stack {
   private:
    std::vector<T> v;

   public:
    bool empty() const { return v.empty(); }
    void push(const T& item) { v.push_back(item); }
    T& top() {
        if (empty()) std::out_of_range("Stack Is Empty");
        return v.back();
    }
    void pop() { v.pop_back(); }

    template <typename U>
    friend Stack<U> operator+(const Stack<U>& a, const Stack<U>& b);
};

template <typename T>
Stack<T> operator+(const Stack<T>& a, const Stack<T>& b) {
    Stack<T> c{a};

    std::for_each(b.v.cbegin(), b.v.cend(),
                  [&](T element) { c.v.push_back(element); });

    return c;
}
