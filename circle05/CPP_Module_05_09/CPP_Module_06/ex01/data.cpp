#include "data.hpp"

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data a;
    a.d1 = 42;
    a.d2 = 3.14;

    std::cout << "ptr d     " << &a<< std::endl;

    uintptr_t ptr = serialize(&a);
    Data* b = deserialize(ptr);

    std::cout << "ptr d2    " << b << std::endl;
    std::cout << "d1: " << b->d1 << std::endl;
    std::cout << "d2: " << b->d2 << std::endl;
}