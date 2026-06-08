#pragma once
// 2.1

/*
template <typename T>
T min(const T& a, const T& b) {
    if (a < b) {
        return a;
    }
    return b;
}
*/

// 2.2
template <typename T>
T min(const T& a, const T& b) {
    return (a > b) ? b : a;
}
