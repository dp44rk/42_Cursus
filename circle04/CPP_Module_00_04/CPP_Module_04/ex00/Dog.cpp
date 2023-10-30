#include "Dog.hpp"

Dog::Dog( void ) {
    std::cout << "Dog default constructor called" << std::endl;
    this->setType("Dog");
}

Dog::Dog( const Dog& src ){
    std::cout << "Dog copy constructor called" << std::endl;
    this->setType(src.getType());
}

Dog::~Dog ( void ) {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator = ( const Dog& src ) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src)
        this->setType(src.getType());
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "[Dog] Woooof Woooof U・ﻌ・U" << std::endl;
}