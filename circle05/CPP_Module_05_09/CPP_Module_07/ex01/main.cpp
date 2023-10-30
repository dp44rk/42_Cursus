#include "iter.hpp"

// print array
void test_1( const int &d ) {
    std::cout << d << std::endl;
}

// initializes an array
void test_2( int &d ) {
    d = 0;
}

int main() {
    int arr[3] = {1, 2, 3};
    // iter(arr, 3, test_1); // const
    iter(arr, 3, test_2); // non const
    for (int i = 0; i < 3; i++) std::cout << arr[i] << std::endl;
}