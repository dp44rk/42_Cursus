#include "span.hpp"

/**
 *  > ./ex01
 *  2
 *  14
*/
int main() {
    // {
    //     try {
    //         Span sp = Span(5);
    //         sp.addNumber(6);
    //         sp.addNumber(3);
    //         sp.addNumber(17);
    //         sp.addNumber(9);
    //         sp.addNumber(11);
    //         std::cout << sp.shortestSpan() << std::endl;
    //         std::cout << sp.longestSpan() << std::endl;
    //         // for (std::multiset<int>::iterator it = sp._s.begin(); it != sp._s.end(); ++it)
    //         //     std::cout << *it << " ";
    //     }
    //     catch (std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    // }

    {
        Span s(3);

        s.addNumber(-2147483648);
        s.addNumber(2147483647);

        std::cout << s.longestSpan() << std::endl;
        std::cout << s.shortestSpan() << std::endl;

        s.addNumber(0);

        std::cout << s.longestSpan() << std::endl;
        std::cout << s.shortestSpan() << std::endl;
    }

    {
        Span sp(5);
        int tmp[] = { 6, 3, 17, 9, 11};
        std::vector<int> v (tmp, tmp + sizeof(tmp) / sizeof(int) );
        
        sp.addNumber(v.begin(), v.end());
        
        std::cout << sp.longestSpan() << std::endl; //14
        std::cout << sp.shortestSpan() << std::endl; //2
        
        try
        {
            sp.addNumber(42);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
