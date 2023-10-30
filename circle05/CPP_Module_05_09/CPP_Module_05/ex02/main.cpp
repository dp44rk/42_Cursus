#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void test( AForm &f, Bureaucrat &b) {
    std::cout << std::endl;

    std::cout << f;
    std::cout << b << std::endl;

    std::cout << std::endl;
    b.signForm(f);
    std::cout << std::endl;
    std::cout << f;
    std::cout << std::endl;

    b.executeForm(f);

    std::cout << std::endl;
}

// 145 137
void enterShrubbery( void ){
    ShrubberyCreationForm s("one");
    Bureaucrat A("a", 1); // 모두 ok
    // Bureaucrat B("b", 146); // 모두 불가능
    // Bureaucrat C("c", 138); // sign만 가능

    test(s, A);
    std::cout << "------------------------------------------------" << std::endl;
    // test(s, B);
    // std::cout << "------------------------------------------------" << std::endl;
    // test(s, C);
}

// 72 45
void enterRobot( void ){
    RobotomyRequestForm r("two");
    Bureaucrat A("a", 1); // 모두 ok
    // Bureaucrat B("b", 146); // 모두 불가능
    // Bureaucrat C("c", 47); // sign만 가능

    test(r, A);
    std::cout << "------------------------------------------------" << std::endl;
    // test(r, B);
    // std::cout << "------------------------------------------------" << std::endl;
    // test(r, C);
}

// 25 5
void enterPresidential( void ) {
    PresidentialPardonForm p("three");
    Bureaucrat A("a", 1); // 모두 ok
    // Bureaucrat B("b", 30); // 모두 불가능
    // Bureaucrat C("c", 10); // sign만 가능

    test(p, A);
    std::cout << "------------------------------------------------" << std::endl;
    // test(p, B);
    // std::cout << "------------------------------------------------" << std::endl;
    // test(p, C);
}

int main ( void ) {
    try {
        // enterShrubbery();
        enterRobot();
        // enterPresidential();
    }
    catch (std::exception& e) {
        std::cerr << RED << e.what() << DEFAULT << std::endl;
    }

    return 0;
}