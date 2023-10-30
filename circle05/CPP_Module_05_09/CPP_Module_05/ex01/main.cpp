#include "Form.hpp"

int main( void ) {
	try {
		Bureaucrat  b1("b1", 21);
		Bureaucrat  b2("b2", 80);

		Form  f1("f1", 30, 30);
		Form  f2("f2", 75, 30);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;


		b1.signForm(f1);
		b2.signForm(f2);

		std::cout << std::endl;

		std::cout << f1 << std::endl; // true
		std::cout << f2 << std::endl; // 

		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	return 0;
}