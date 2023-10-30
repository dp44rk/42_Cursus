#ifndef CPP04_WRONGANIMAL_HPP_
#define CPP04_WRONGANIMAL_HPP_

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;
public:
    WrongAnimal( void );
    WrongAnimal( const WrongAnimal& src );
    virtual ~WrongAnimal( void ); // virtual or not?
    // ~WrongAnimal( void );
    WrongAnimal& operator=( const WrongAnimal& src );
    std::string getType( void ) const;
    void setType( std::string type );
    void makeSound( void ) const;
};

#endif