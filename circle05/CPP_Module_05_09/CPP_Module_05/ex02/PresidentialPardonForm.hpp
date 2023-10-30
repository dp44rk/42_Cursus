#ifndef MODULE05_PRESIDENTIALPARDONFORM_HPP
#define MODULE05_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm( void );
        virtual ~PresidentialPardonForm( void );
        PresidentialPardonForm( const PresidentialPardonForm &src );
        PresidentialPardonForm &operator=( const PresidentialPardonForm &src );
        PresidentialPardonForm( std::string target );

        virtual void execute( Bureaucrat const &executor ) const;

};

#endif