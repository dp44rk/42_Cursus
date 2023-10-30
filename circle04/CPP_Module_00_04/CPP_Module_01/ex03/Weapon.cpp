#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : m_type(type) {
	std::cout << "\033[0;32m" "Constructor called for " << m_type << "\033[0m"  <<std::endl;
}

Weapon::Weapon(){
	std::cout << "\033[0;32m" "Constructor called for Weapon" << "\033[0m"  <<std::endl;
};


Weapon::~Weapon(){
	std::cout << "\033[0;31m""Destructor called for " << m_type << "\033[0m" <<std::endl;
}

const   std::string& Weapon::getType(){ return m_type; }

void    Weapon::setType( std::string _type ){
    m_type = _type;
}