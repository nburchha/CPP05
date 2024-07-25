#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeSign(50), _gradeExec(50)
{
	// std::cout << "AForm default constructor called!" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	// std::cout << "AForm param constructor called!" << std::endl;
	if (_gradeSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeSign > 150)
		throw AForm::GradeTooLowException();
	if (_gradeExec < 1)
		throw AForm::GradeTooHighException();
	if (_gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	// std::cout << "AForm destructor called!" << std::endl;
}

AForm& AForm::operator=(AForm const& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

AForm::AForm(AForm const& other) : _name(other.getName()), _signed(other.getSigned()), _gradeSign(other.getGradeSign()), _gradeExec(other.getGradeExec()) {}

std::string const AForm::getName() const
{
	return _name;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExec() const
{
	return _gradeExec;
}

bool AForm::getSigned() const
{
	return _signed;
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!\n";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!\n";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!\n";
}

std::ostream& operator<<(std::ostream& out, AForm const& Aform)
{
	out << "Name: " << Aform.getName() << ", signed: " << std::boolalpha << Aform.getSigned() << ", grade to sign: " << Aform.getGradeSign() << ", grade to execute: " << Aform.getGradeExec() << std::endl;
	return out;
}
