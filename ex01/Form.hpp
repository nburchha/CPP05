#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExec;
	public:
		void beSigned(Bureaucrat const& bureaucrat);
		//getters
		std::string const getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;
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