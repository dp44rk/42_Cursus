#include "Cat.hpp"

Cat::Cat( void ) {
    std::cout << "Cat default constructor called" << std::endl;
    this->setType("Cat");
    _brain = new Brain();
}

Cat::Cat( const Cat& src ){
    std::cout << "Cat copy constructor called" << std::endl;
    this->setType(src.getType());
    _brain = new Brain(*src._brain);
}

Cat::~Cat ( void ) {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat& Cat::operator = ( const Cat& src ) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &src) {
        this->setType(src.getType());
        *_brain = *src._brain;
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "[Cat] Meoooooooooow =^._.^= ∫" << std::endl;
}