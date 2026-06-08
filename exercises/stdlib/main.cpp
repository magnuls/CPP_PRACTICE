#include <graph.h>

#include <iostream>

#include "graph.h"
#include "stack.h"
#include "template.cpp"

void stack_test();
void test_graph();

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

    // stack_test();
    test_graph();

    return 0;
}

void test_graph() {
    std::vector start = {1, 1, 1, 5, 5, 4};
    std::vector end = {2, 3, 4, 4, 2, 2};

    Graph g(start, end);

    for (const auto& elem : g) {
        std::cout << "Number of Adjacent Nodes for " << elem << ": "
                  << g.numOutgoing(elem) << '\n';
    }
    std::cout << std::endl;

    for (const auto& elem : g) {
        std::vector<int> edges{g.adjacent(elem)};
        std::cout << "Outgoing Edges Node(" << elem << "): ";
        std::for_each(edges.cbegin(), edges.cend(),
                      [&](const int& element) { std::cout << element << " "; });
        std::cout << std::endl;
    }
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
