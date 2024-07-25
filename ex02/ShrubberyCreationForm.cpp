#include "ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::ofstream file(std::string(_target + "_shrubbery").c_str());
	if (file.fail())
		throw FileNotOpenedException();
	file << create_trees();
}

std::string ShrubberyCreationForm::create_trees() const
{
	std::string tree = "            $$\n\
            $$\n\
           $$$$\n\
          $$$$$$$\n\
         $$$$$$$$$\n\
        $$$$$$$$$$$\n\
       $$$$$$$$$$$$$\n\
      $$$$$$$$$$$$$$$\n\
     $$$$$$$$$$$$$$$$$\n\
    $$$$$$$$$$$$$$$$$$$\n\
   $$$$$$$$$$$$$$$$$$$$$\n\
  $$$$$$$$$$$$$$$$$$$$$$$\n\
           $$$$$\n\
           $$$$$\n\
           $$$$$\n\
    \n         @@@\n\
         @@@\n\
        @@@@@\n\
        @@@@@\n\
       @@@@@@@\n\
      @@@@@@@@@\n\
     @@@@@@@@@@@\n\
    @@@@@@@@@@@@@\n\
   @@@@@@@@@@@@@@@\n\
  @@@@@@@@@@@@@@@@@\n\
         @@@\n\
         @@@\n\
         @@@\n";
	return (tree);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	// std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
		AForm::operator=(copy);
	}
	return (*this);
}

const char* ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
	return ("File could not be opened.");
}
