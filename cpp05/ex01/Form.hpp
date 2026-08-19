#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form
{
	private:
		const std::string _name;
		bool is_signed;
		const int _grade_sign;
		const int _grade_exec;
	public:
		Form();
		~Form();
};

#endif