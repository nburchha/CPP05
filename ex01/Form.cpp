#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeSign(50), _gradeExec(50)
{
	std::cout << "Form default constructor called!" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (_gradeSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeSign > 150)
		throw Form::GradeTooLowException();
	if (_gradeExec < 1)
		throw Form::GradeTooHighException();
	if (_gradeExec > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form param constructor called!" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called!" << std::endl;
}

Form& Form::operator=(Form const& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::Form(Form const& other) : _name(other.getName()), _signed(other.getSigned()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec()) {}

std::string const Form::getName() const
{
	return _name;
}

int Form::getGradeSign() const
{
	return _gradeSign;
}

int Form::getGradeExec() const
{
	return _gradeExec;
}

bool Form::getSigned() const
{
	return _signed;
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!\n";
}

std::ostream& operator<<(std::ostream& out, Form const& form)
{
	out << "Name: " << form.getName() << ", signed: " << std::boolalpha << form.getSigned() << ", grade to sign: " << form.getGradeSign() << ", grade to execute: " << form.getGradeExec() << std::endl;
	return out;
}
