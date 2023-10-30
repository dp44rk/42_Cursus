#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
    std::cout << "ScavTrap[" << m_name << "] :" <<
        "This time it'll be awesome, I promise!" << std::endl;
    this->m_HP = 100;
    this->m_EP = 50;
    this->m_AD = 20;
}

ScavTrap::ScavTrap( std::string &name ): ClapTrap(name) {
    std::cout << "ScavTrap[" << m_name << "] :" <<
        "This time it'll be awesome, I promise!" << std::endl;
    this->m_name = name;
    this->m_HP = 100;
    this->m_EP = 50;
    this->m_AD = 20;
}

ScavTrap::ScavTrap( ScavTrap &src ) : ClapTrap(src) {
    std::cout << "ScavTrap[" << m_name << "] :" <<
        "This time it'll be awesome, I promise!" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
        std::cout << "ScavTrap[" << m_name << "] :" <<
            "I'll get you next time!" << std::endl;
}

ScavTrap    &ScavTrap::operator = ( const ScavTrap &src ) {
    if (this != &src) {
        this->m_name = src.getName();
        this->m_HP = src.getHP();
        this->m_EP = src.getEP();
        this->m_AD = src.getAD();
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (!m_HP)
        std::cout << "ScavTrap[" << m_name << "] Already Dead." << std::endl;
    else if (!m_EP) {
        std::cout << "ScavTrap[" << m_name << "] :" <<
            "ATTACK_ERROR: Oh well. NOt Enough Energy" << std::endl;
        return ;
    }
    m_EP--;
    std::cout << "ScavTrap[" << m_name << "] attacks " << target <<
        ", causing " << m_AD << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap[" << m_name << "] :" <<
        "I have entered in Gate keeper mode." << std::endl;
}
std::ostream& operator << (std::ostream &o, const ScavTrap &c) { 
    return o << "ScavTrap [" << c.getName() << "]: HP(" << c.getHP() << "), EP(" << c.getEP() << "), AD(" << c.getAD() << ")" ;
} 
