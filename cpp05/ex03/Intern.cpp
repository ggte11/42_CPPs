#include "Intern.hpp"

const char *Intern::NotExixtingFormException::what() const throw() {
	return ("Form does not exist!");
}

Intern::Intern() {

}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {

}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *form = NULL;
	int i;
	for (i = 0; i < 3; i++)
		if (formName == names[i])
			break ;
	try
	{
		switch (i)
		{
			case 0:
				form = new PresidentialPardonForm(target);
				break ;
			case 1:
				form = new RobotomyRequestForm(target);
				break ;
			case 2:
				form = new ShrubberyCreationForm(target);
				break ;
			default:
				throw (NotExixtingFormException());
		}
		std::cout << "Intern creates " << names[i] << " form!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return form;
}
