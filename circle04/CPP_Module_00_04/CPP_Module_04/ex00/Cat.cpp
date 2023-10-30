#include "Cat.hpp"

Cat::Cat( void ) {
    std::cout << "Cat default constructor called" << std::endl;
    this->setType("Cat");
}

Cat::Cat( const Cat& src ){
    std::cout << "Cat copy constructor called" << std::endl;
    this->setType(src.getType());
}

Cat::~Cat ( void ) {
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator = ( const Cat& src ) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src)
        this->setType(src.getType());
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "[Cat] Meoooooooooow =^._.^= ∫" << std::endl;
}