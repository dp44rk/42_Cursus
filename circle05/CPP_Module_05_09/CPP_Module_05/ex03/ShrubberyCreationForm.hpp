#ifndef MODULE05_SHRUBBERYCREATIONFORM_HPP
#define MODULE05_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm( void );
        virtual ~ShrubberyCreationForm( void );
        ShrubberyCreationForm( const ShrubberyCreationForm &src );
        ShrubberyCreationForm &operator=( const ShrubberyCreationForm &src );
        ShrubberyCreationForm( std::string target );

        virtual void execute( Bureaucrat const &executor ) const;

        class OpenErrorException: public std::exception {
            public:
            const char * what( void ) const throw();
        };
};

#endif