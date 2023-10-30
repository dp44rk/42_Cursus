#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

void test (std::string type) { // name
    Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm(type, "Bender");

    std::cout << std::endl;
    std::cout << *rrf << std::endl;
    std::cout << std::endl;
    delete rrf;

}

int main ( void ) {
    try {
        test("shrubbery creation");
        test("robotomy request");
        test("presidential pardon");
        test("error");
    }
    catch (std::exception &e) {
        std::cout << RED << e.what() << DEFAULT << std::endl;
    }


    return 0;
}