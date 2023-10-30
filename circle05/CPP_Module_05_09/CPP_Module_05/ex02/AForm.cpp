#include "AForm.hpp"

AForm::AForm( void ) : _Name("default"), _isSigned(false),_SignGrade(150), _ExecGrade(150), _target("default") {
    std::cout << "Form Default Constructor called" << std::endl;
}

AForm::~AForm( void ) {
    std::cout << "Form Destructor called" << std::endl;
}

AForm::AForm( std::string name, int signGrade, int execGrade, std::string target)
        :_Name(name), _isSigned(false), _SignGrade(signGrade), _ExecGrade(execGrade), _target(target) {
    std::cout << _Name << ": Form Constructor called" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm &AForm::operator=( const AForm &src ) {
    std::cout << "Form Assignation operator called" << std::endl;
    if (this != &src) {
        *(const_cast<std::string*>(&_Name)) = src.getName();
        _isSigned = src.getIsSigned();
        *(const_cast<int*>(&_SignGrade)) = src.getSignGrade();
        *(const_cast<int*>(&_ExecGrade)) = src.getExecGrade();
        _target = src.getTarget();
    }
    return *this;
}

AForm::AForm( const AForm &src )
        : _Name(src.getName()), _isSigned(src.getIsSigned()), _SignGrade(src.getSignGrade()), _ExecGrade(src.getExecGrade()), _target(src.getTarget()) {
    std::cout << src.getName() << ": Form Copy Constructor called" << std::endl;
}

std::string AForm::getName( void ) const {
    return this->_Name;
}

bool AForm::getIsSigned( void ) const {
    return this->_isSigned;
}

int AForm::getSignGrade( void ) const {
    return this->_SignGrade;
}

int AForm::getExecGrade( void ) const {
    return this->_ExecGrade;
}

std::string AForm::getTarget( void ) const {
    return this->_target;
}

const char *AForm::GradeTooHighException::what( void ) const throw() {
    return "Grade is too high";
}

const char * AForm::GradeTooLowException::what( void ) const throw() {
    return "Grade is too low";
}

const char * AForm::FormNotSignedException::what( void ) const throw() {
    return "Form is not signed";
}

std::ostream &operator<<( std::ostream &o, AForm &f ) {
    o << "==================="<< std::endl;
    o << "<" << f.getName() << " Form>" << std::endl;
    o << "Signed: " << std::boolalpha << f.getIsSigned() << std::endl;
    o << "Sign Grade: " << f.getSignGrade() << std::endl;
    o << "Execute Grade: " << f.getExecGrade() << std::endl;
    o << "Target: " << f.getTarget() << std::endl;
    o << "===================" << std::endl;
    return o;
}

void AForm::beSigned( const Bureaucrat &b ) {
    if (b.getGrade() > this->_SignGrade)
        throw AForm::GradeTooLowException();
    else
        this->_isSigned = true;
}

void AForm::isExecute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->_ExecGrade)
        throw AForm::GradeTooLowException();
    else if (!this->_isSigned)
        throw AForm::FormNotSignedException();
}
