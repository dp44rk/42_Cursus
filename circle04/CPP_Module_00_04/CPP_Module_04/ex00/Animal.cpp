#include "Animal.hpp"


Animal::Animal( void ) : _type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( const Animal& src ) {
    std::cout << "Animal copy constructor called" << std::endl;
    _type = src.getType();
}

Animal::~Animal( void ) {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& src) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &src)
        this->_type = src.getType();
    return *this;
}

std::string Animal::getType( void ) const {
    return this->_type;
}

void Animal::makeSound( void ) const {
    std::cout << "[Animal] Animal Sound" << std::endl;
}

void Animal::setType( std::string type ) {
    this->_type = type;
}