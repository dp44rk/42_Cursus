#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap() {
    ClapTrap::m_name = m_name + "_clap_name";
    this->m_HP = F_HP;
    this->m_EP = S_EP;
    this->m_AD = F_AD;
    std::cout << "DiamondTrap[" << this->m_name << "] :" <<
        "Glitching weirdness is a term of endearment, right?" << std::endl;
}

DiamondTrap::DiamondTrap( std::string &name ) : ScavTrap(name), FragTrap(name) {
    ClapTrap::m_name = name + "_clap_name";
    this->m_name = name;
    this->m_HP = F_HP;
    this->m_EP = S_EP;
    this->m_AD = F_AD;
    std::cout << "DiamondTrap[" << m_name << "] :" <<
        "Glitching weirdness is a term of endearment, right?" << std::endl;
}
DiamondTrap::DiamondTrap( FragTrap &src ) {
    ClapTrap::m_name = src.getName() + "_clap_name";
    this->m_name = src.getName();
    std::cout << "DiamondTrap[" << m_name << "] :" <<
        "Glitching weirdness is a term of endearment, right?" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap[" << m_name << "] :" <<
        "Crap happens." << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &src ) {
    if (this != &src) {
        ClapTrap::m_name = src.getName() + "_clap_name";
        this->m_name = src.getName();
        this->m_HP = src.getHP();
        this->m_EP = src.getEP();
        this->m_AD = src.getAD();
    }
    return *this;
}

std::string DiamondTrap::getName( void ) const{
    return this->m_name;
}

std::ostream& operator << (std::ostream &o, const DiamondTrap &c) { 
    return o << "DiamondTrap [" << c.getName() << "]: HP(" << c.getHP() << "), EP(" << c.getEP() << "), AD(" << c.getAD() << ")" ;
} 

void    DiamondTrap::attack( const std::string& target ) {
    ScavTrap::attack( target );
}

void    DiamondTrap::whoAmI( void ) {
    std::cout<< "The ClapTrap name of DiamondTrap[" <<
        this->m_name << "] is " << ClapTrap::m_name << std::endl;
}
