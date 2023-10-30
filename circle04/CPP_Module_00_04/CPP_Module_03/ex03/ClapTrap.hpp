#ifndef _CLAPTRAP_HPP
#define _CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
    std::string     m_name;
    unsigned int    m_HP;
    unsigned int    m_EP;
    unsigned int    m_AD;
    
public:
    ClapTrap( void );
    ClapTrap( std::string &name );
    virtual ~ClapTrap( void );
    ClapTrap( ClapTrap &src );
    ClapTrap    &operator = ( const ClapTrap &src );

    virtual std::string     getName( void ) const;
    unsigned int    getHP( void ) const;
    unsigned int    getEP( void ) const;
    unsigned int    getAD( void ) const;

    virtual void    attack(const std::string& target);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);
    void            printStatus( void );
};

std::ostream& operator << (std::ostream &o, const ClapTrap &ClapTrap);

#endif