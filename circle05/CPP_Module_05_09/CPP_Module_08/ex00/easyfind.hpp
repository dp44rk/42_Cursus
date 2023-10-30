# pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &c, const int val) {
    return std::find(c.begin(), c.end(), val);
}

template <typename T>
typename T::const_iterator easyfind(const T &c, const int val) {
    return std::find(c.begin(), c.end(), val);
}