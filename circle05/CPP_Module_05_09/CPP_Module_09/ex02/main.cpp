#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cout << "Error: Invalid argument." << std::endl;
        return 1;
    }

    try {
        PmergeMe inst;
        inst.parse(ac, av);
        inst.sort();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    catch (const char *errorMessage) {
        std::cout << errorMessage << std::endl;
    }

    return 0;
}