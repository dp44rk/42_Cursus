#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;


	std::cout << "\033[1;31mMemory address of the string : \033[0m" << &str << std::endl;
	std::cout << "\033[1;31mMemory address held by stringPTR : \033[0m" << stringPTR << std::endl;
	std::cout << "\033[1;31mMemory address held by stringREF : \033[0m" << &stringREF << std::endl;
	std::cout << "\033[1;31mValue of the string : \033[0m" << str << std::endl;
	std::cout << "\033[1;31mValue pointed to by stringPTR  : \033[0m" << *stringPTR << std::endl;
	std::cout << "\033[1;31mValue pointed to by stringREF : \033[0m" << stringREF << std::endl;

	std::cout << "\033[1;32m**********************\033[0m" << std::endl;

	str = "HI THIS IS ZOMBIE";
	std::cout << "\033[1;31mMemory address of the string : \033[0m" << &str << std::endl;
	std::cout << "\033[1;31mMemory address held by stringPTR : \033[0m" << stringPTR << std::endl;
	std::cout << "\033[1;31mMemory address held by stringREF : \033[0m" << &stringREF << std::endl;
	std::cout << "\033[1;31mValue of the string : \033[0m" << str << std::endl;
	std::cout << "\033[1;31mValue pointed to by stringPTR  : \033[0m" << *stringPTR << std::endl;
	std::cout << "\033[1;31mValue pointed to by stringREF : \033[0m" << stringREF << std::endl;



}
