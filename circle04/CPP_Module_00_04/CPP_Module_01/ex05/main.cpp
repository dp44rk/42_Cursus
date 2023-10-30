#include "Harl.hpp"

int main(void)
{
    Harl h;

    h.complain("DEBUG");
    std::cout << "\n";
    h.complain("INFO");
    std::cout << "\n";
    h.complain("WARNING");
    std::cout << "\n";
    h.complain("ERROR");
    return 0;
}