#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void presidential_pardon_test()
{
    Bureaucrat thomas("Thomas", 1);
    Bureaucrat low_level_bureaucrat("Low level bureaucrat", 140);
    PresidentialPardonForm presidential_form("A Turkey");

    std::cout << "\n---------Presidential Pardon---------\n";
    presidential_form.beSigned(thomas);
    std::cout << "Thomas (grade one) tries to execute the form\n";
    thomas.executeForm(presidential_form);
    std::cout << "\nLow (grade 140) tries to execute the form\n";
    low_level_bureaucrat.executeForm(presidential_form);
}

void robotomy_request_test()
{
    Bureaucrat thomas("Thomas", 7);
    Bureaucrat low_level_guy("Low level bureaucrat", 140);
    RobotomyRequestForm automate_it_please("robotomy");

    std::cout << "\n--------ROBOTOMY REQUEST TEST--------\n";
    automate_it_please.beSigned(thomas);

    thomas.executeForm(automate_it_please);
    low_level_guy.executeForm(automate_it_please);
}

void shrubbery_test()
{
    Bureaucrat thomas("Thomas", 6);
    Bureaucrat low_level_guy("Mark", 140);
    ShrubberyCreationForm create_a_tree_for_me("trees");

    std::cout << "\n------SHRUBBERY CREATE A TREE------\n";
    create_a_tree_for_me.beSigned(thomas);
    thomas.executeForm(create_a_tree_for_me);
    low_level_guy.executeForm(create_a_tree_for_me);
}

int main()
{
    presidential_pardon_test();
    robotomy_request_test();
    shrubbery_test();
    return 0;
}
