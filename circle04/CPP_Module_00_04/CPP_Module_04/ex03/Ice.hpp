#ifndef CPP04_ICE_HPP_
#define CPP04_ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
private:
public:
    Ice( void );
    Ice(Ice const & src);
    Ice & operator=(Ice const & src);
    ~Ice( void );
    Ice(std::string const & type);

    AMateria* clone() const;
    void use( ICharacter& target );
    // void use(std::string const & target);
};
#endif