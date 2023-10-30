#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
}

Cure::Cure( Cure const & src ) : AMateria(src.getType()) {
}

Cure::~Cure( void ) {
}

Cure &Cure::operator=( Cure const & src ) {
    if (this != &src) {
        this->_type = src.getType();
    }
    return *this;
}

Cure::Cure(std::string const & type) : AMateria(type) {
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    AMateria::use(target);
}