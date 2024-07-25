#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void internCreateFormCorrect()
{
	AForm *testForm;
	Intern fred;
	Bureaucrat thomas("Thomas", 24);

	std::cout << "\n---------Intern Tries to create Form: Success---------\n";
	try {
	testForm = fred.makeForm("presidential pardon", "Mr. Jackson");
	std::cout << "YES intern good job, you created a form" << std::endl;
	} catch (std::exception &exception) {
	std::cout << "Oh no! That does not work!: " << exception.what() << std::endl;
	return ;
	}
	thomas.signForm(*testForm);
	thomas.executeForm(*testForm);
	delete testForm;
}

void internCreateFormWrong()
{
	AForm *testForm;
	Intern fred;
	Bureaucrat thomas("Thomas", 5);

	std::cout << "\n---------Intern Tries to create Form: Fail---------\n";
	try {
	testForm = fred.makeForm("Wrong Form", "Mr. Jackson");
	std::cout << "YES intern good job, you created a form" << std::endl;
	} catch (std::exception &exception) {
		std::cout << "Oh no! That does not work!: " << exception.what() << std::endl;
	}
	(void) testForm;
}

int main()
{
	internCreateFormCorrect();
	internCreateFormWrong();
	return 0;
}
