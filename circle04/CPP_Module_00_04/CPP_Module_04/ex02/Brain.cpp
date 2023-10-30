#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "idea" + std::to_string(i);
}

Brain::Brain( const Brain& src ) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->setIdea(i, src.getIdea(i));
    }
}

Brain::~Brain( void ) {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& src ) {
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; i++) {
            this->setIdea(i, src.getIdea(i));
        }
    }
    return *this;
}

std::string Brain::getIdea( int idx ) const {
    return this->_ideas[idx];
}

void Brain::setIdea( int idx, std::string idea ) {
    this->_ideas[idx] = idea;
}