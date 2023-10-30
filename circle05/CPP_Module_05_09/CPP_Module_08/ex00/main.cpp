#include "easyfind.hpp"


int main() {
    //   typename T::iterator easyfind(T &c, const int val)
    {
        std::vector<int> v;

        for (int i = 0; i < 10; ++i)
            v.push_back(i);

        for (int i = 0; i < 10; ++i)
            std::cout << v[i] << " ";
        std::cout << std::endl;

        v.push_back(3);

        for (int i = 0; i < 11; ++i)
            std::cout << v[i] << " ";
        std::cout << std::endl;

        v.pop_back();

        std::cout << *easyfind(v, 3) << std::endl;
        // std::cout << *easyfind(v, 100) << std::endl; // == end(), *****ub
    }

    //   typename T::iterator easyfind(T &c, const int val)
    {
        std::vector<int> v;
        for (int i = 0; i < 10; ++i)
            v.push_back(i);
        
        for (int i = 0; i < 10; ++i)
            std::cout << v[i] << " ";
        std::cout << std::endl;

        *easyfind(v, 3) = 0; 

        for (int i = 0; i < 10; ++i)
            std::cout << v[i] << " ";
        std::cout << std::endl;
    }
    
    // typename T::const_iterator easyfind(const T &c, const int val)
    {
        std::vector<int> v;
        for (int i = 0; i < 10; ++i)
            v.push_back(i);
        const std::vector<int> &cv = v;

        std::cout << *easyfind(cv, 3) << std::endl;
    }
}