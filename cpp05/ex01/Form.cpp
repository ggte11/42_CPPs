#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _is_signed(false) {

}

Form::Form(const Form &other) : _name(other.getName()), _grade_sign(other.getGradeSign()), _grade_exec(other.getGradeExec()), _is_signed(false) {

}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_is_signed = other.Is_Signed();
	return *this;
}

Form::~Form() {
}


std::string Form::getName() const {
	return (_name);
}

int Form::getGradeSign() const {
	return (_grade_sign);
}

int Form::getGradeExec() const {
	return (_grade_exec);
}

bool Form::Is_Signed() const {
	return (_is_signed);
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
	out << obj.getName() << ": Grade to sign " << obj.getGradeSign() << ", Grade to execute: " << obj.getGradeExec() << ", ";
	if (obj.Is_Signed())
		out << "Form is signed.";
	else
		out << "Form is not signed.";
	return out;
}