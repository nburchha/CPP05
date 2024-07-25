#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		AForm *makeForm(std::string form_name, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
	private:
		AForm *createShrubberyCreationForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createPresidentialPardonForm(std::string target);
};