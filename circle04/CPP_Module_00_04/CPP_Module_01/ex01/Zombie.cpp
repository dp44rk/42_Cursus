#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Constructor called" << std::endl;
}

Zombie::Zombie( const std::string name ) : m_name(name) {
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie()
{ std::cout << "Destructor called" <<std::endl; }

void Zombie::setName( std::string& name_inpt)
{
	m_name = name_inpt;
}

void Zombie::announce(void)
{ std::cout << "<" << m_name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl; }
