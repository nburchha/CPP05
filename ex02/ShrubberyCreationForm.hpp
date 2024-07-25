#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		ShrubberyCreationForm();
		std::string create_trees() const;
	public:
		void execute(Bureaucrat const& executor) const;
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		class FileNotOpenedException : public std::exception
		{
			virtual const char* what() const throw();
		};
};