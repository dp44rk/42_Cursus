#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		// try
		// {
		// 	Bureaucrat test("test", 1080);
		// }
		// catch(const std::exception& e)
		// {
        //     std::cerr << "inside catch" << '\n';
		// 	std::cerr << RED << e.what() << DEFAULT << '\n';
        //     // throw; // outside catch에서도 실행된다.
		// }
		
		std::cout << std::endl;

		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << std::endl;
		
		a.incrementGrade();
		b.decrementGrade();
	
		std::cout << std::endl;

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << std::endl;

        if (1) { // 예외처리 실행
            a.decrementGrade();
            b.incrementGrade();
            a.decrementGrade();
            b.incrementGrade();
        }

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
        std::cerr << "outside catch" << '\n';
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
	
	return (0);
}