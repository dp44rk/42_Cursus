#include "Zombie.hpp"

int main(void)
{
	int	N = 7;
	Zombie *hord = zombieHorde(N, "zombie");
	for(int i = 0; i < N; i++)
		hord[i].announce();
	delete [] hord;
	return 0;
}
