#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *newone = new Zombie(name);
	newone->setName(name);
	return newone;
}

