#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeSign;
		int const _gradeExec;
		AForm();
	public:
		virtual void execute(Bureaucrat const& executor) const = 0;
		//getters
		std::string const getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSigned() const;
		//setters
		void beSigned(Bureaucrat const& bureaucrat);
		//cannonical
		AForm(std::string name, int gradeSign, int gradeExec);
		virtual ~AForm();
		AForm& operator=(AForm const& other);
		AForm(AForm const& copy);
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, AForm const& Aform);