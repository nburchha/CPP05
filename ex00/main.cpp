#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 0);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		Bureaucrat b2("b2", 1560);
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
		b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return 0;
}