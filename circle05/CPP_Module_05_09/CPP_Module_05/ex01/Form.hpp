#ifndef MODULE05_FORM_HPP
#define MODULE05_FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string _Name;
    bool _isSigned;
    const int _SignGrade;
    const int _ExecGrade;

public:
    Form( void );
    ~Form( void );
    Form( std::string name, int signGrade, int execGrade );
    Form &operator=( const Form &src );
    Form( const Form &src );

    std::string getName( void ) const;
    bool getIsSigned( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;

    class GradeTooHighException : public std::exception {
        public:
          const char * what( void ) const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
          const char * what( void ) const throw();
    };
    void beSigned( const Bureaucrat &b );
};

std::ostream &operator<<( std::ostream &o, Form &f );


#endif