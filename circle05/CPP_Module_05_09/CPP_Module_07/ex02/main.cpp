#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL); // Array<T>( unsigned int n )
    const Array<int> cnumbers(MAX_VAL); // Array<T>( unsigned int n )
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value; // operator[] 함수가 해당 요소에 대한 참조를 반환 -> 해당 요소에 대한 값을 변경
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers; // Array<T>( Array<T> const &src )
        Array<int> test(tmp); // Array<T>( Array<T> const &src )
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}