#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("default"), _Grade(150) {
    std::cout << _Name << ": Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << _Name << ": Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _Name(name) {
    std::cout << _Name << ": Bureaucrate constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else {
        this->_Grade = grade;
    }
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &src ) {
    std::cout << _Name << ": Bureaucrat assignation operator called" << std::endl;
    if (this != &src) {
        this->_Grade = src.getGrade(); }
        *(const_cast<std::string*>(&_Name)) = src.getName();
    return *this;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : _Name(src.getName()), _Grade(src.getGrade()) {
    std::cout << _Name << ":: Bureaucrat copy constructor called" << std::endl;
}

std::string Bureaucrat::getName() const {
    return this->_Name;
}

int Bureaucrat::getGrade() const {
    return this->_Grade;
}

void Bureaucrat::incrementGrade() {
    this->_Grade > 1 ? this->_Grade-- : throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    this->_Grade < 150 ? this->_Grade++ : throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
void Bureaucrat::signForm( Form &f ) const {
    try {
        f.beSigned(*this);
        std::cout << GREEN << getName() << " signed " << f.getName() << DEFAULT << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << getName() << " couldn't sign " << f.getName() << " because "
            << e.what() << DEFAULT << std::endl;
    }
}
