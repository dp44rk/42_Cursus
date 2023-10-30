#include "HumanB.hpp"

HumanB::HumanB( std::string _name ) : m_name(_name) {
	std::cout << "\033[0;32m" "Constructor called for " << m_name << "\033[0m"  <<std::endl;
}

HumanB::~HumanB(){
	std::cout << "\033[0;31m""Destructor called for " << m_name << "\033[0m" <<std::endl;
}

void    HumanB::attack(){
    std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon &_weapon ){
    m_weapon = &_weapon;
}