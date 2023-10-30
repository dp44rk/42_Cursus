#ifndef CPP04_WRONGCAT_HPP_
#define CPP04_WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat( void );
    WrongCat( const WrongCat& src );
    ~WrongCat ( void );
    WrongCat& operator=( const WrongCat& src );
    void makeSound( void ) const;
};

#endif