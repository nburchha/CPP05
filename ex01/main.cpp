#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form 		F1("FBI", 45, 10);
	Bureaucrat	Thorben("Thorben", 100);

	std::cout << std::endl;
	std::cout << Thorben;
	std::cout << F1;
	std::cout << std::endl;
	Thorben.signForm(F1);

	std::cout << "Second test:" << std::endl;
	Bureaucrat	Peter("Peter", 10);
	try {
		F1.beSigned(Peter);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
