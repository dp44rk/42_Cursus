#ifndef FRAGTRAP_HPP 
#define FRAGTRAP_HPP 

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap( void );
    FragTrap( std::string &name );
    ~FragTrap( void );
    FragTrap( FragTrap &src );
    FragTrap    &operator = ( const FragTrap &src );

    void    highFivesGuys( void );
};

std::ostream& operator << (std::ostream &o, const FragTrap &c);

#endif