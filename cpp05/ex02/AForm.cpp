#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::high() const throw() {
	return ("Grade is to high!");
}

const char *AForm::GradeTooLowException::low() const throw() {
	return ("Grade is to low!");
}

const char *AForm::FormNotSignedException::sign() const throw() {
	return ("Form is not signed!");
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _is_signed(false) {
	if (_grade_exec < 1 || _grade_sign < 1)
		throw(GradeTooHighException());
	if (_grade_exec > 150 || _grade_sign > 150)
		throw(GradeTooLowException());
}

AForm::AForm(const AForm &other) : _name(other.getName()), _grade_sign(other.getGradeSign()), _grade_exec(other.getGradeExec()), _is_signed(false) {

}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_is_signed = other.Is_Signed();
	return *this;
}

AForm::~AForm() {
}


std::string AForm::getName() const {
	return (_name);
}

int AForm::getGradeSign() const {
	return (_grade_sign);
}

int AForm::getGradeExec() const {
	return (_grade_exec);
}

bool AForm::Is_Signed() const {
	return (_is_signed);
}

void AForm::beSigned(const Bureaucrat &sign) {
	if (sign.getGrade() > getGradeSign())
		throw(GradeTooLowException());
	else
		_is_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!_is_signed)
		throw(FormNotSignedException());
	if (executor.getGrade() > _grade_exec)
		throw(GradeTooLowException());
	executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
	out << obj.getName() << ": Grade to sign " << obj.getGradeSign() << ", Grade to execute: " << obj.getGradeExec() << ", ";
	if (obj.Is_Signed())
		out << "AForm is signed.";
	else
		out << "AForm is not signed.";
	return out;
}