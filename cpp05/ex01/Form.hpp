#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _grade_sign;
		const int _grade_exec;
		bool _is_signed;
	public:
		Form(std::string name, int grade_sign, int grade_exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		class GradeTooHighException : public std::exception {
		public:
			const char *high() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *low() const throw();
		};
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool Is_Signed() const;
		void beSigned(const Bureaucrat &sign);
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif