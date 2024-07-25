#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*form_creators[3])(std::string target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == form_names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (this->*form_creators[i])(target);
		}
	}
	throw FormNotFoundException();
	return NULL;
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found!");
}