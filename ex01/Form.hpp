#pragma once

#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExec;
	public:
		//getters
		std::string const getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;
		//setters
		void beSigned(Bureaucrat const& bureaucrat);
		//cannonical
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();
		Form& operator=(Form const& other);
		Form(Form const& copy);
		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, Form const& form);