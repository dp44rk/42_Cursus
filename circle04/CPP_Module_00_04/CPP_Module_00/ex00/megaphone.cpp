#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while(*++argv)
	{
		std::string str = *argv;
		for (int x = 0; x < str.length(); x++)
			putchar(toupper(str[x]));
		if (*(argv + 1))
			std::cout << " ";
	}
	return 0;
}
