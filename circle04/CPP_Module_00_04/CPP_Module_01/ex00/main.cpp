#include "Zombie.hpp"

int main()
{
	Zombie z1("z1");
	z1.announce();

	Zombie *z2 = newZombie("z2");
	randomChump("z3");
	delete z2;
	return 0;
}
