#ifndef MODULE05_ROBOTOMYREQUESTFORM_HPP
#define MODULE05_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm( void );
        virtual ~RobotomyRequestForm( void );
        RobotomyRequestForm( const RobotomyRequestForm &src );
        RobotomyRequestForm &operator=( const RobotomyRequestForm &src );
        RobotomyRequestForm( std::string target );

        virtual void execute( Bureaucrat const &executor ) const;
};

#endif