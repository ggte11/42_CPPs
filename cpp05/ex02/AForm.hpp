#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int _grade_sign;
		const int _grade_exec;
		bool _is_signed;
	public:
		AForm(std::string name, int grade_sign, int grade_exec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		class GradeTooHighException : public std::exception {
			public:
				const char *high() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *low() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *sign() const throw();
		};
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool Is_Signed() const;
		void beSigned(const Bureaucrat &sign);
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif