#ifndef CPP04_DOG_HPP_
#define CPP04_DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog( void );
    Dog( const Dog& src );
    ~Dog ( void );
    Dog& operator=( const Dog& src );
    void makeSound( void ) const;
};

#endif