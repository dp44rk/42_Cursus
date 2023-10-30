#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("S", 145, 137, "default") {
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) : AForm("S", src.getSignGrade(), src.getExecGrade(), src.getTarget()) {
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
    return (*(dynamic_cast<ShrubberyCreationForm*>(&(AForm::operator=(src)))));
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("S", 145, 137, target) {
    std::cout << "ShrubberyCreationForm target Constructor called" << std::endl;
}

const char *ShrubberyCreationForm::OpenErrorException::what( void ) const throw() {
    return "because the file failed to open.";
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
    try {
        isExecute(executor);
        std::ofstream fo(this->getTarget() + "_shrubbery");
        if (!fo.is_open())
            throw ShrubberyCreationForm::OpenErrorException();
        std::string s = 
        "                              # #### ##\n"
        "                            ### \\/#|### |/####\n"
        "                           ##\\/#/ \\||/##/_/##/_#\n"
        "                         ###  \\/###|/ \\/ # ###\n"
        "                       ##_\\_#\\_\\## | #/###_/_####\n"
        "                      ## #### # \\ #| /  #### ##/##\n"
        "                       __#_--###`  |{,###---###-~\n"
        "                                 \\ }{\n"
        "                                  }}{\n"
        "                                  }}{\n"
        "                                  {{}\n"
        "                              -=-~{ .-^- _\n"
        "                                  `}\n";
        fo << s << std::endl;
        fo.close();
        std::cout << GREEN << this->getTarget() << " has been executed successfully!" << DEFAULT << std::endl;
    }
    catch ( std::exception &e ) {
        std::cout << RED << "Fail to execute, because " << e.what() << DEFAULT << std::endl;
    }
}
