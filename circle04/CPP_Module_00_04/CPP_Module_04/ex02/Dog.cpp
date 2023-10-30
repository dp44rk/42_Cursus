#include "Dog.hpp"

Dog::Dog( void ) {
    std::cout << "Dog default constructor called" << std::endl;
    this->setType("Dog");
    _brain = new Brain();
}

Dog::Dog( const Dog& src ){
    std::cout << "Dog copy constructor called" << std::endl;
    this->setType(src.getType());
    _brain = new Brain(*src._brain);
}

Dog::~Dog ( void ) {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator = ( const Dog& src ) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &src) {
        this->setType(src.getType());
        *_brain = *src._brain;
    }
    return *this;
}
void Dog::makeSound( void ) const {
    std::cout << "[Dog] Woooof Woooof U・ﻌ・U" << std::endl;
}