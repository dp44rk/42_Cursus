# include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
    : m_name("default"), m_HP(10), m_EP(10), m_AD(0) {
        std::cout << "ClapTrap[" << m_name << "] :" <<
            "Let's get this party started!" << std::endl;
    }

ClapTrap::ClapTrap( std::string &name )
    : m_name(name), m_HP(10), m_EP(10), m_AD(0) {
        std::cout << "ClapTrap[" << m_name << "] :" <<
            "Let's get this party started!" << std::endl;
    }

ClapTrap::~ClapTrap( void ) {
        std::cout << "ClapTrap[" << m_name << "] :" <<
            "Argh arghargh death gurgle gurglegurgle urgh... death." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap &src )
    : m_name(src.getName()), m_HP(src.getHP()), m_EP(src.getEP()), m_AD(src.getAD()) {
    std::cout << "ClapTrap[" << m_name << "] :" <<
        "This time it'll be awesome, I promise!" << std::endl;
}

ClapTrap    &ClapTrap::operator = ( const ClapTrap &src ) {
    if (this != &src) {
        this->m_name = src.getName();
        this->m_HP = src.getHP();
        this->m_EP = src.getEP();
        this->m_AD = src.getAD();
    }
    return *this;
}

std::string ClapTrap::getName( void ) const {
    return m_name;
}

unsigned int         ClapTrap::getHP( void ) const {
    return m_HP;
}

unsigned int         ClapTrap::getEP( void ) const {
    return m_EP;
}

unsigned int         ClapTrap::getAD( void ) const {
    return m_AD;
}

void        ClapTrap::attack(const std::string& target) {
    if (!m_HP)
        std::cout << "ClapTrap[" << m_name << "] Already Dead." << std::endl;
    else if (!m_EP) {
        std::cout << "ClapTrap[" << m_name << "] :" <<
            "ATTACK_ERROR: Poop. NOt Enough Energy" << std::endl;
        return ;
    }
    m_EP--;
    std::cout << "Meatsplosion! ClapTrap[" << this->m_name <<
     "] attacks " << target << ", causing [" << m_AD << "] poins of damage!" << std::endl;
}

void        ClapTrap::takeDamage(unsigned int amount) {
    if (!m_HP)
        std::cout << "ClapTrap[" << m_name << "] Already Dead." << std::endl;
    else if (m_HP < amount) {
        m_HP = 0;
        std::cout << "Robot down! ClapTrap[" << m_name << "] Died." << std::endl;
    }
    else {
        m_HP -= amount;
        std::cout << "My robotic flesh! AAHH! ClapTrap[" << m_name <<
            "] has taken damage! (" << m_HP << ")" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (!m_HP)
        std::cout << "ClapTrap[" << m_name << "] Already Dead." << std::endl;
    else if (!m_EP) {
        std::cout << "ClapTrap[" << m_name << "] :" <<
            "REPAIR_ERROR: Poop. NOt Enough Energy" << std::endl;
    }
    else {
        m_EP--;
        m_HP += amount;
        std::cout << "Can I just say... yeehaw. " <<
            "ClapTrap[" << m_name << "] Repaired [" << amount <<
            "] HP. (" <<m_HP << ")" << std::endl;
    }
}

std::ostream& operator << (std::ostream &o, const ClapTrap &c) { 
    return o << "ClapTrap [" << c.getName() << "]: HP(" << c.getHP() << "), EP(" << c.getEP() << "), AD(" << c.getAD() << ")" ;
}