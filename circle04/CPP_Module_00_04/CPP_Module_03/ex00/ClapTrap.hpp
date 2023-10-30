#ifndef _CLAPTRAP_HPP
#define _CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
    std::string m_name;
    unsigned int         m_HP;
    unsigned int         m_EP;
    unsigned int         m_AD;
    
public:
    ClapTrap( void );
    ClapTrap( std::string &name );
    ~ClapTrap( void );
    ClapTrap( ClapTrap &src );
    ClapTrap    &operator = ( const ClapTrap &src );

    std::string         getName( void ) const;
    unsigned int        getHP( void ) const;
    unsigned int        getEP( void ) const;
    unsigned int        getAD( void ) const;

    void                attack(const std::string& target);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    void                printStatus( void );
};

std::ostream& operator << (std::ostream &o, const ClapTrap &ClapTrap);

#endif