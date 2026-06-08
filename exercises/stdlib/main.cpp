#include <iostream>

#include "stack.h"
#include "template.cpp"

void stack_test();

int main() {
    /*
    std::vector<int> v;
    for (int i{}; i < 4; ++i) {
        v.push_back(i);
    }

    for (auto itr{v.crbegin()}; itr != v.crend(); ++itr) {
        std::cout << *itr << '\n';
    }
    */

    stack_test();
    return 0;
}

void stack_test() {
    Stack<int> a, b;
    a.push(1);
    a.push(2);
    a.push(3);

    b.push(4);
    b.push(5);
    b.push(6);
    // b = {4,5,6}
    // a = {1,2,3}

    // a + b = {1,2,3,4,5,6}
    Stack<int> c = a + b;

    while (!(c.empty())) {
        std::cout << c.top() << '\n';
        c.pop();
    }
}
