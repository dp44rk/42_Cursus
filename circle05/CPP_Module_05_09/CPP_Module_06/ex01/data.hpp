#ifndef CPP06_EX01_DATA_CPP
#define CPP06_EX01_DATA_CPP

#include <iostream>

struct Data {
    int d1;
    double d2;
};


uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif