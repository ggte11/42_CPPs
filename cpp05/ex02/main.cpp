#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		std::cout << boss << std::endl;

		ShrubberyCreationForm shrub("garden");
		std::cout << shrub << std::endl;

		boss.signForm(shrub);
		std::cout << shrub << std::endl;

		boss.executeForm(shrub);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Low", 150);
		RobotomyRequestForm robot("C3PO");

		low.signForm(robot);
		low.executeForm(robot);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalid("Bad", 0);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalid2("Bad2", 151);
		std::cout << invalid2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}