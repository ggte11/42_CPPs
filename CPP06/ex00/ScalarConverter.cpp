#include "ScalarConverter.hpp"

static bool isChar(const std::string &str) {
	if (str.size() != 1)
		return false;
	char c = static_cast<char>(str[0]);
	return (c <= 127 && !std::isdigit(c));
}

static bool isInt(const std::string &str, int &out) {
	if (str.empty())
		return false;
	
}

void ScalarConverter::Convert(std::string literal) {

}