#include <iostream>
#include <vector>

int main() {
    int n{};
    std::cin >> n;
    std::vector<std::vector<int>> vector(n);

    int q{};
    std::cin >> q;

    int k{};
    int temp{};
    int index{};

    while (n > 0) {
        std::cin >> k;
        for (int i{}; i < k; ++i) {
            std::cin >> temp;
            vector[index].push_back(temp);
        }
        ++index;
        --n;
    }

    int i{};
    int j{};
    while (q > 0) {
        std::cin >> i;
        std::cin >> j;
        std::cout << vector[i][j] << '\n';
        --q;
    }

    return 0;
}

// n q              ← number of arrays, number of queries
// k a0 a1 ... ak  ← first number is the length, rest are the elements
// k a0 a1 ... ak  ← repeat n times
// i j              ← query: arr[i][j]
// i j              ← repeat q times
