#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::high() const throw() {
	return ("Grade is to high! Max: 1");
}

const char *Bureaucrat::GradeTooLowException::low() const throw() {
	return ("Grade is to low! Min: 150");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	try {
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		_grade = grade;
	}
	catch (const GradeTooHighException & h) {
		std::cout << h.high() << std::endl;
		_grade = 1;
	}
	catch (const GradeTooLowException & l) {
		std::cout << l.low() << std::endl;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::incrementgrade() {
	try {
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (const GradeTooHighException & e) {
		std::cout << e.high() << std::endl;
	}
}

void Bureaucrat::decrementgrade() {
	try {
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch (const GradeTooLowException & e) {
		std::cout << e.low() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &get) {
	out << get.getName() << ", bureaucrat grade " << get.getGrade();
	return (out);
}

void Bureaucrat::signForm(Form &obj) {
	try
	{
		obj.beSigned(*this);
		std::cout << getName() << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << getName() << " couldnt sign " << obj.getName() << std::endl;
	}
}