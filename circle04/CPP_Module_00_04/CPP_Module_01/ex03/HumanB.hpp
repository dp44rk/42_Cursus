#ifndef _HumanB
#define _HumanB

#include "Weapon.hpp"
#include <iostream>
#include <string>

class   HumanB{
private:
    Weapon      *m_weapon;
    std::string m_name;

public:
    HumanB( std::string _name );
    ~HumanB();
    void    attack();
    void    setWeapon( Weapon &m_weapon );
};

#endif