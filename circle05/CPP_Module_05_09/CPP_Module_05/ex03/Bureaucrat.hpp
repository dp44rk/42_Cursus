#ifndef MODULE05_BUREAUCRAT_HPP
#define MODULE05_BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

const std::string DEFAULT = "\033[39m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";

class Bureaucrat {
private:
    const std::string _Name;
    int _Grade; // 1 - 150

public:
    Bureaucrat( void );
    ~Bureaucrat( void );
    Bureaucrat( std::string name, int grade );
    Bureaucrat( const Bureaucrat &src );
    Bureaucrat &operator=( const Bureaucrat &src );

    std::string getName( void ) const;
    int getGrade( void ) const;
    void incrementGrade( void );
    void decrementGrade( void );

	class GradeTooHighException : public std::exception {
		public:
		  const char * what( void ) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
		  const char * what( void ) const throw();
	};
  void signForm( AForm &f ) const;
  void executeForm( AForm const &f );
};

std::ostream &operator<<( std::ostream &o, Bureaucrat &b );

#endif