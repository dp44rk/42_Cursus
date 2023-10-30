#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("P", 25, 5, "default") {
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm("P", src.getSignGrade(), src.getExecGrade(), src.getTarget()) {
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src ) {
    return (*(dynamic_cast<PresidentialPardonForm*>(&(AForm::operator=(src)))));
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("P", 25, 5, target) {
    std::cout << "PresidentialPardonForm target Constructor called" << std::endl;
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
    try {
        isExecute(executor);
        std::cout << GREEN << "[" << this->getTarget() << "] has been pardoned by Zafod Beeblebrox" << DEFAULT << std::endl;
    }
    catch ( std::exception &e ) {
        std::cout << RED << "Fail to execute, because " << e.what() << DEFAULT << std::endl;
    }
}
