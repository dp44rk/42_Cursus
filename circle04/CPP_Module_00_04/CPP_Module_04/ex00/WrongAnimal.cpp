#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->setType("WrongAnimal");
}

WrongAnimal::WrongAnimal( const WrongAnimal& src ) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->setType(src.getType());
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& src ) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    if (this != &src)
        this->setType(src.getType());
    return *this;
}

std::string WrongAnimal::getType( void ) const {
    return this->_type;
}

void WrongAnimal::setType( std::string type ) {
    this->_type = type;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "[WrongAnimal] WrongAnimal Sound" << std::endl;
}
