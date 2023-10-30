#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("R", 72, 45, "default") {
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm("R", src.getSignGrade(), src.getExecGrade(), src.getTarget()) {
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
    return (*(dynamic_cast<RobotomyRequestForm*>(&(AForm::operator=(src)))));
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("R", 72, 45, target) {
    std::cout << "RobotomyRequestForm target Constructor called" << std::endl;
}

void RobotomyRequestForm::execute( Bureaucrat const &e) const {
    try {
        isExecute(e);
        srand(time(NULL));
        std::cout << "Whirrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
        if (rand() % 2)
            std::cout << GREEN << this->getTarget() << " has been robotomized successfully!" << DEFAULT << std::endl;
        else
            std::cout << RED << "[" << this->getTarget() << "] has failed to be robotomized" << DEFAULT << std::endl;
    }
    catch ( std::exception &e ) {
        std::cout << RED << "Fail to execute, because" << e.what() << DEFAULT << std::endl;
    }
}