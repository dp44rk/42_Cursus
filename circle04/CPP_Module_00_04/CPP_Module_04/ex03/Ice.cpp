#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
}

Ice::Ice( Ice const & src ) : AMateria(src.getType()) {
}

Ice::~Ice( void ) {
}

Ice &Ice::operator=( Ice const & src ) {
    if (this != &src) {
        this->_type = src.getType();
    }
    return *this;
}

Ice::Ice(std::string const & type) : AMateria(type) {
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
}