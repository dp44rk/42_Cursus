#include "Intern.hpp" 

Intern::Intern( void ) {
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::~Intern( void ) {
    std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern( const Intern &src ) {
    std::cout << "Intern Copy Constructor called" << std::endl;
    *this = src;
}

Intern &Intern::operator=( const Intern &src ) {
    std::cout << "Intern Assignation operator called" << std::endl;
    (void)src;
    return *this;
}
	
AForm* Intern::ShrubberyCreation(const std::string& target) const {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::RobotomyRequest(const std::string& target) const {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::PresidentialPardon(const std::string& target) const {
    return (new PresidentialPardonForm(target));
}

const char *Intern::FormDoesNotExistException::what( void ) const throw() {
    return "Form does not exist";
}

AForm* Intern::makeForm( std::string name, std::string target ) const {
    std::string const forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    FP fp[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};
    for (int i = 0; i < 3; i++) {
        if (name == forms[i]) {
            std::cout << "Intern creates [" << name << "]" << std::endl;
			return (this->*(fp[i]))(target);
        }
    }
    throw Intern::FormDoesNotExistException();
    return NULL;
}