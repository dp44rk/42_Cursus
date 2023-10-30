#include "Form.hpp"

Form::Form( void ) : _Name("default"), _isSigned(false), _SignGrade(150), _ExecGrade(150) {
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::~Form( void ) {
    std::cout << "Form Destructor called" << std::endl;
}

Form::Form( std::string name, int signGrade, int execGrade ) : _Name(name), _isSigned(false), _SignGrade(signGrade), _ExecGrade(execGrade) {
    std::cout << _Name << ": Form Constructor called" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=( const Form &src ) {
    std::cout << "Form Assignation operator called" << std::endl;
    if (this != &src) {
        *(const_cast<std::string*>(&_Name)) = src.getName();
        _isSigned = src.getIsSigned();
        *(const_cast<int*>(&_SignGrade)) = src.getSignGrade();
        *(const_cast<int*>(&_ExecGrade)) = src.getExecGrade();
    }
    return *this;
}

Form::Form( const Form &src ) : _Name(src.getName()), _isSigned(src.getIsSigned()), _SignGrade(src.getSignGrade()), _ExecGrade(src.getExecGrade()) {
    std::cout << src.getName() << ": Form Copy Constructor called" << std::endl;
}

std::string Form::getName( void ) const {
    return this->_Name;
}

bool Form::getIsSigned( void ) const {
    return this->_isSigned;
}

int Form::getSignGrade( void ) const {
    return this->_SignGrade;
}

int Form::getExecGrade( void ) const {
    return this->_ExecGrade;
}

const char *Form::GradeTooHighException::what( void ) const throw() {
    return "Grade is too high";
}

const char * Form::GradeTooLowException::what( void ) const throw() {
    return "Grade is too low";
}

std::ostream &operator<<( std::ostream &o, Form &f ) {
    o << "==================="<< std::endl;
    o << "<" << f.getName() << " Form>" << std::endl;
    o << "Signed: " << std::boolalpha << f.getIsSigned() << std::endl;
    o << "Sign Grade: " << f.getSignGrade() << std::endl;
    o << "Execute Grade: " << f.getExecGrade() << std::endl;
    o << "==================="<< std::endl;
    return o;
}

void Form::beSigned( const Bureaucrat &b ) {
    if (b.getGrade() > this->_SignGrade)
        throw Form::GradeTooLowException();
    else
        this->_isSigned = true;
}