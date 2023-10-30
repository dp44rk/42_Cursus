#ifndef CPP04_CAT_HPP_
#define CPP04_CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat( void );
    Cat( const Cat& src );
    ~Cat ( void );
    Cat& operator=( const Cat& src );
    void makeSound( void ) const;
};

#endif