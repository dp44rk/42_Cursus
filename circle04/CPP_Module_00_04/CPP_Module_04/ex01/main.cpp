#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void check_leaks( void ) {
    system("leaks ex01");
}

int main( void ) {
    if (0) {
        const int n = 10;
        Animal* arr[n];
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) arr[i] = new Dog();
            else arr[i] = new Cat();
        }

        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            delete arr[i];
        } 
    }

    if (1) {
        Animal* A = new Cat();
        Animal* B = new Cat();
        *A = *B;
        delete A;
        delete B;
    }

    atexit(check_leaks);
}