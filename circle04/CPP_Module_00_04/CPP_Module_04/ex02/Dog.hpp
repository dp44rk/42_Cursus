#ifndef CPP04_DOG_HPP_
#define CPP04_DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* _brain;

public:
    Dog( void );
    Dog( const Dog& src );
    ~Dog ( void );
    Dog& operator=( const Dog& src );
    void makeSound( void ) const;
};

#endif