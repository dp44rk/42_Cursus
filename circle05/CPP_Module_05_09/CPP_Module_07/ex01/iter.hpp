#pragma once

#include <iostream>

template <typename T>
void iter(T *arr, std::size_t l, void (*f)(T &)) {
    // std::cout << "func general" << std::endl;
    if(!arr || !l || !f)
        return;
    for (std::size_t i = 0; i < l; i++)
        f(arr[i]);
}

template <typename T>
void iter(const T *arr, std::size_t l, void (*f)(const T &)) {
    // std::cout << "func const" << std::endl;
    if(!arr || !l || !f)
        return;
    for (std::size_t i = 0; i < l; i++)
        f(arr[i]);
}
