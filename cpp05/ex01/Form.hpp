#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_sign;
		const int _grade_exec;
	public:
		Form(std::string name, int grade_sign, int grade_exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool Is_Signed() const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif