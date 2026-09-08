#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(std::string type, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		class GradeTooHighException : public std::exception {
		public:
			const char *high() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *low() const throw();
		};
		std::string getName() const;
		int getGrade() const;
		void incrementgrade();
		void decrementgrade();
		void signForm(AForm &obj);
		void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif