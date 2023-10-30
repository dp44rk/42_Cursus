#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon &_weapon ) : m_name(_name), m_weapon(_weapon) {
	std::cout << "\033[0;32m" "Constructor called for " << m_name << "\033[0m"  <<std::endl;
}

HumanA::~HumanA(){
	std::cout << "\033[0;31m""Destructor called for " << m_name << "\033[0m" <<std::endl;
}

void    HumanA::attack(){
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}