#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"
class Character : public ICharacter {
private:
    AMateria*   _inven[4];
    std::string _name;
public:
    Character( void );
    Character( std::string const & name );
    Character( Character const & src );
    Character & operator=( Character const & src );
    ~Character( void );

    std::string const &getName() const;
    void equip( AMateria* m );
    void unequip( int idx );
    void use( int idx, ICharacter& target );
};
#endif