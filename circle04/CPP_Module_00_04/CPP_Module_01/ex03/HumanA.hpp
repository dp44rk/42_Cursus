#ifndef _HumanA
#define _HumanA

#include "Weapon.hpp"
#include <iostream>
#include <string>

class   HumanA{
private:
    Weapon      &m_weapon;
    std::string m_name;

public:
    HumanA( std::string _name, Weapon &_weapon );
    ~HumanA();
    void    attack();
};

#endif