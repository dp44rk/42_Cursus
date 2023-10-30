#ifndef CPP04_ANIMAL_HPP_
#define CPP04_ANIMAL_HPP_

#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;
public:
    Animal( void );
    Animal( const Animal& src );
    virtual ~Animal( void );
    Animal& operator=( const Animal& src );
    std::string getType( void ) const;
    void setType( std::string type );
    virtual void makeSound( void ) const = 0;
};

#endif