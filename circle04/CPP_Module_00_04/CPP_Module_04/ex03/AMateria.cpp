#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("default") { }

AMateria::AMateria( AMateria const & src ) {
    this->_type = src.getType();
}

AMateria & AMateria::operator=( AMateria const & src ) {
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

AMateria::~AMateria( void ) {
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::setType(std::string const & type) {
    this->_type = type;
}

void AMateria::use(ICharacter& target) {
    (void)&target;
    // std::cout << "AMateria::use(ICharacter& target) - " << target.getName() << std::endl;
}