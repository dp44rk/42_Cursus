#ifndef _Zombie
#define _Zombie

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string m_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName( std::string& name_inpt);
	void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
