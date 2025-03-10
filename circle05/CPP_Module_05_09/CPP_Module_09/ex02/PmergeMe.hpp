# pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <algorithm>

struct Group {
public:
    std::vector<int> _c;

    Group() {}
    Group(int val) { _c.push_back(val); }
    Group(const Group &other) { *this = other; }

    Group(const Group &smaller, const Group &bigger) {
        _c.insert(_c.end(), smaller._c.begin(), smaller._c.end());
        _c.insert(_c.end(), bigger._c.begin(), bigger._c.end());
    }

    Group &operator=(const Group &other) {
        if (this != &other)
            _c = other._c;
        return *this;
    }

    bool operator>(const Group &other) const {
        if (_c.size() != other._c.size())
            return !!_c.size();
        return _c.back() > other._c.back();
    }

    bool operator<(const Group &other) const {
        if (_c.size() != other._c.size())
            return !other._c.size();
        return _c.back() < other._c.back();
    }

    void swap(Group &other) {
        if (this == &other)
            return;

        std::vector<int> temp = _c;
        _c = other._c;
        other._c = temp;
    }

    void divide(Group &bigger, Group &smaller) {
        size_t half = _c.size() / 2;

        bigger._c = std::vector<int>(_c.begin() + half, _c.end());
        smaller._c = std::vector<int>(_c.begin(), _c.begin() + half);
    }

    void extractNumber(int &smaller, int &bigger) {
        smaller = _c[0];
        bigger = _c[1];
    }

    int getNumber(int idx) { return _c[idx]; }

    const std::vector<int> &getC() { return _c; }

    void print() {
        std::cout << "    Group: ";
        for (size_t i = 0; i < _c.size(); i++)
            std::cout << _c[i] << " ";
        std::cout << std::endl;
    }
};

class PmergeMe
{
private:
    std::vector<int> _c;
    std::vector<int> _dp;

public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe(void);

    void parse(int ac, char **av);
    int atoiPositive(const std::string &str);
    void printVec(std::vector<int> &vec);
    void printVec2(const std::string &head, std::vector<int> &vec);

    std::vector<int> fordJohnsonSort(std::vector<int> arr);
    std::vector<Group> recur(std::vector<Group> arr);
    
    std::deque<int> fordJohnsonSort(std::deque<int> arr);
    std::deque<Group> recur(std::deque<Group> arr);
    
    int jacobsthal(int n);
    
    void sort(void);

    void printDuration(clock_t start, clock_t end, size_t n, const char *data);
};
