#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
    std::cout << "WrongCat default constructor called" << std::endl;
    this->setType("WrongCat");
}

WrongCat::WrongCat( const WrongCat& src ) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->setType(src.getType());
}

WrongCat::~WrongCat( void ) {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& src ) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this != &src)
        this->setType(src.getType());
    return *this;
}

void WrongCat::makeSound( void ) const {
    std::cout << "[Cat] Grrrrrrrrrrrrrr <(*ΦωΦ*)>" << std::endl;
}
