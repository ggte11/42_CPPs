#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileErrorException::file() const throw() {
	return ("Error on opening the file");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), 145, 137), _target(other._target) {
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw (FileErrorException());
	file << "       ,,,.   ,,  .oo8888o.\n";
	file << "    ,&%%&%&&%,   ,8888\\88/8o\n";
	file << "   ,%&\\%&&%&&%, 88\\88888/88'8\n";
	file << "   %&&%&%&/%&&%@ 888\\88888'88\n";
	file << "   %&&%/ %&%%&&@  `88\\8 `/88'\n";
	file << "   `&%\\ ` /%&'       \\   / \n";
	file << "       |o|            | |\n";
	file << "       |.|            | |\n";
	file << "   \\\\/ ._\\//_/__/  ,\\_//__\\/" << std::endl;
	file.close();
}