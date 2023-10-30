#ifndef MODULE05_INTERN_HPP
#define MODULE05_INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern( void );
    ~Intern( void );
    Intern( const Intern &src );
    Intern &operator=( const Intern &src );
    std::string getTarget( void ) const;

    AForm* ShrubberyCreation(const std::string& target) const;
    AForm* RobotomyRequest(const std::string& target) const;
    AForm* PresidentialPardon(const std::string& target) const;

    class FormDoesNotExistException : public std::exception {
        public:
          const char * what( void ) const throw();
    };


    AForm* makeForm( std::string name, std::string target ) const;
};

typedef AForm* (Intern::*FP)(const std::string&) const;
#endif