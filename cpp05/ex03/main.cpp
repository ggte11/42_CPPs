#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		Bureaucrat low("Low", 150);
		std::cout << boss << std::endl;
		std::cout << low << std::endl;
		AForm *form1 = intern.makeForm("shrubbery creation", "garden");
		if (form1) {
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		AForm *form2 = intern.makeForm("robotomy request", "C3PO");
		if (form2) {
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		AForm *form3 = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form3) {
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}
		AForm *form4 = intern.makeForm("invalid form", "test");
		if (form4) {
			boss.signForm(*form4);
			boss.executeForm(*form4);
			delete form4;
		}
		ShrubberyCreationForm shrub("garden");
		std::cout << shrub << std::endl;
		boss.signForm(shrub);
		std::cout << shrub << std::endl;
		boss.executeForm(shrub);
		RobotomyRequestForm robot("C3PO");
		low.signForm(robot);
		low.executeForm(robot);
		Bureaucrat invalid("Bad", 0);
		std::cout << invalid << std::endl;
		Bureaucrat invalid2("Bad2", 151);
		std::cout << invalid2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}