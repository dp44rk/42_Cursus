#ifndef _PHONEBOOK
#define _PHONEBOOK

#include <cctype>
#include <cstdio>
#include <iomanip>
#include <string>
#include "contact.hpp"
#define C_GREEN_B "\033[1;32m"
#define C_GREEN "\033[0;32m"
#define C_RESET "\033[0m"

class Phonebook
{
	private:
		Contact contacts[8];

	public:
		void	add(const int idx);
		void	search(const int i);
		void	displayall();
};

#endif
