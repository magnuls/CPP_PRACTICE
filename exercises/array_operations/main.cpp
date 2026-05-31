#include <stdio.h>

#include <iostream>

using namespace std;

size_t length(const char* ptr) {
    const char* s = ptr;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - s;
}

// Uses References
void swap(int& i1, int& i2) {
    int temp = i2;
    i2 = i1;
    i1 = temp;
}

// Uses Pointers
void swap(int* const ptr1, int* const ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    char* oddOrEven = "Never odd or even";
    char* nthCharPtr = &oddOrEven[5];
    --(--nthCharPtr);
    cout << *nthCharPtr << '\n';
    char** pointerPtr = &nthCharPtr;
    cout << **pointerPtr << '\n';
    nthCharPtr++;
    cout << nthCharPtr - oddOrEven;

    return 0;
}
