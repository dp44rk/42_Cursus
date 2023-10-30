#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
    std::cout << "FragTrap[" << m_name << "] :" <<
        "Recompiling my combat code!" << std::endl;
    this->m_HP = 100;
    this->m_EP = 100;
    this->m_AD = 30;
}

FragTrap::FragTrap( std::string &name ): ClapTrap(name) {
    std::cout << "FragTrap[" << m_name << "] :" <<
        "Recompiling my combat code!" << std::endl;
    this->m_name = name;
    this->m_HP = 100;
    this->m_EP = 100;
    this->m_AD = 30;
}

FragTrap::FragTrap( FragTrap &src ) : ClapTrap(src) {
    std::cout << "FragTrap[" << m_name << "] :" <<
        "Recompiling my combat code!" << std::endl;
}

FragTrap::~FragTrap( void ) {
        std::cout << "FragTrap[" << m_name << "] :" <<
            "No fair! I wasn't ready." << std::endl;
}

FragTrap    &FragTrap::operator = ( const FragTrap &src ) {
    if (this != &src) {
        this->m_name = src.getName();
        this->m_HP = src.getHP();
        this->m_EP = src.getEP();
        this->m_AD = src.getAD();
    }
    return *this;
}

void    FragTrap::highFivesGuys( void ) {
    std::cout << "FragTrap[" << m_name << "] :" <<
        "Secret handshake! High five!" << std::endl;
}

std::ostream& operator << (std::ostream &o, const FragTrap &c) { 
    return o << "FragTrap [" << c.getName() << "]: HP(" << c.getHP() << "), EP(" << c.getEP() << "), AD(" << c.getAD() << ")" ;
}
