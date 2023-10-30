#ifndef _Zombie
#define _Zombie

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string m_name;

public:
	Zombie(std::string name);
	~Zombie();
	void setName( std::string& name_inpt);
	void announce(void);
};

Zombie*	newZombie( std::string name );
void		randomChump( std::string name );

#endif