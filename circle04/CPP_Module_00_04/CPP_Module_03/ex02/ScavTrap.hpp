#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap( void );
    ScavTrap( std::string &name );
    ~ScavTrap( void );
    ScavTrap( ScavTrap &src );
    ScavTrap    &operator = ( const ScavTrap &src );

    void    attack(const std::string& target);
    void    guardGate( void );
};

std::ostream& operator << (std::ostream &o, const ScavTrap &ClapTrap);

#endif