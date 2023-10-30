#ifndef FRAGTRAP_HPP 
#define FRAGTRAP_HPP 

#include "ClapTrap.hpp"

#define F_HP 100;
#define S_EP 50;
#define F_AD 30;
class FragTrap : virtual public ClapTrap {
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