#ifndef _DIAMONDTRAP_HPP
#define _DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :public ScavTrap, public FragTrap {
private:
    std::string     m_name;
public:
    DiamondTrap( void );
    DiamondTrap( std::string &name );
    DiamondTrap( FragTrap &src );
    ~DiamondTrap( void );
    DiamondTrap &operator = (const DiamondTrap &src );

    std::string getName( void ) const;
    void        attack( const std::string& target );
    void        whoAmI( void );
};

std::ostream& operator << (std::ostream &o, const DiamondTrap &c);
#endif