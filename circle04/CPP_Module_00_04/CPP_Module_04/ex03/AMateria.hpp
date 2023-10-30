#ifndef CPP04_AMATERIA_HPP_
#define CPP04_AMATERIA_HPP_

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
    std::string _type;

public:
    AMateria( void );
    AMateria(AMateria const & src);
    AMateria & operator=(AMateria const & src);
    virtual ~AMateria( void );
    AMateria(std::string const & type);

    std::string const & getType() const; //Returns the materia type
    void setType(std::string const & type);
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif