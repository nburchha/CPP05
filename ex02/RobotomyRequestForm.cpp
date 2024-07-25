#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	std::cout << "Beep Boop" << std::endl;
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully 50% of the time!" << std::endl;
	else
		std::cout << _target << " robotomization failed!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	// std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	AForm::operator=(copy);
	return (*this);
}
