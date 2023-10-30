#ifndef CPP04_CURE_HPP_
#define CPP04_CURE_HPP_

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure( void );
    Cure(Cure const & src);
    Cure & operator=(Cure const & src);
    ~Cure( void );
    Cure(std::string const & type);

    AMateria* clone() const;
    void use( ICharacter& target );
};

#endif