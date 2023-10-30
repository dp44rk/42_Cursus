#ifndef MODULE05_AFORM_HPP
#define MODULE05_AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

// Name을 속성으로, target을 대상으로 -> <target> 변수 추가함.
class AForm {
private:
    const std::string _Name;
    bool _isSigned;
    const int _SignGrade;
    const int _ExecGrade;
    std::string _target;

public:
    AForm( void );
    virtual ~AForm( void );
    AForm( std::string name, int signGrade, int execGrade, std::string target);
    AForm &operator=( const AForm &src );
    AForm( const AForm &src );

    std::string getName( void ) const;
    bool getIsSigned( void ) const;
    int getSignGrade( void ) const;
    int getExecGrade( void ) const;
    std::string getTarget( void ) const;

    class GradeTooHighException : public std::exception {
        public:
          const char * what( void ) const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
          const char * what( void ) const throw();
    };
    class FormNotSignedException : public std::exception {
        public:
          const char * what( void ) const throw();
    };

    void beSigned( const Bureaucrat &b ) ;
    void isExecute(Bureaucrat const & executor) const;
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<( std::ostream &o, AForm &f );


#endif