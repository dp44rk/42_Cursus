#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Error: Invalid arguments." << std::endl;
        return 1;
    }

    try {
        RPN rpn(static_cast<const std::string &>(av[1]));
        rpn.cal();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }
}