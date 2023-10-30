#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void){
    std::srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

/*
    포인터의 경우 dynamic_cast를 사용할 때, 실패하면 NULL을 반환한다.
*/
void identify(Base *p) {
    std::cout << "p: "
    << (dynamic_cast<A *>(p) ? "A" : dynamic_cast<B *>(p) ? "B"
                                   : dynamic_cast<C *>(p) ? "C"
                                   : "?") << std::endl;
}

/*
    레퍼런스의 경우 dynamic_cast를 사용할 때, 실패하면 std::bad_cast 예외를 던진다.(레퍼런스는 null을 가질수 없음)
*/
void identify(Base &p) {
    std::cout << "p: ";
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::exception &e) {
            try {
                (void)dynamic_cast<C &>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::exception &e) {
                std::cout << "?" << std::endl;
            }
        }
    }
}

void leak_test() {
    system("leaks ex02");
}

int main() {
    Base *p = generate();

    if (!p)
        return 1;
    identify(p);
    identify(*p);
    delete p;

    leak_test();
    return 0;
}