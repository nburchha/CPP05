#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	// try{
		Form 		F1("FBI", 45, 10);
		Bureaucrat	Thorben("Thorben", 100);

		std::cout << std::endl;
		std::cout << Thorben;
		std::cout << F1;
		std::cout << std::endl;
		F1.beSigned(Thorben);
		Thorben.signForm(F1);
		std::cout << std::endl;
	// }
	// catch (std::exception& e)
	// {
	// 	std::cout << e.what();
	// }
}