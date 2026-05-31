#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <random>

// Basic Monte Carlo to Calc PI

struct DartInfo {
    double inner{};
    double outer{};
    double total_trials{};
};

DartInfo dartThrows(const long long n) {
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::mt19937 rng{std::random_device{}()};
    DartInfo info{};
    info.total_trials = n;

    for (int i = 0; i < n; i++) {
        double x = uniform(rng);
        double y = uniform(rng);

        if (sqrt((x * x) + (y * y)) <= 1) {
            info.inner++;
        } else {
            info.outer++;
        }
    }
    return info;
}

double calcPi(const DartInfo info) {
    return 4 * info.inner / info.total_trials;
}

int main() {
    double pi = calcPi(dartThrows(100));
    std::cout << pi << '\n';

    pi = calcPi(dartThrows(10000));
    std::cout << pi << '\n';

    pi = calcPi(dartThrows(10000));
    std::cout << pi << '\n';

    auto start = std::chrono::high_resolution_clock::now();
    pi = calcPi(dartThrows(100000000));
    std::cout << std::fixed << std::setprecision(10) << pi << '\n';

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "Duration: " << duration << '\n';

    pi = calcPi(dartThrows(5000000));
    std::cout << std::fixed << std::setprecision(10) << pi << '\n';

    std::cout << "Hello World!" << '\n';
    std::cout << "fuck off" << '\n';

    return 0;
}
