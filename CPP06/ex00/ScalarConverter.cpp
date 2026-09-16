#include "ScalarConverter.hpp"

static bool print_pseudo_literals(std::string &ps_literal) {
	if (ps_literal != "nan" && ps_literal != "nanf"
		&& ps_literal != "+inf" && ps_literal != "+inff"
		&& ps_literal != "-inf" && ps_literal != "-inff")
		return false;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (ps_literal == "nan" || ps_literal == "-inf" || ps_literal == "+inf") {
		std::cout << "float: " << ps_literal << "f" << std::endl;
		std::cout << "double: " << ps_literal << std::endl;
	}
	else {
		std::cout << "float: " << ps_literal << std::endl;
		std::cout << "double: " << ps_literal.substr(0, ps_literal.size() - 1) << std::endl;
	}
	return true;
}

static bool isChar(const std::string &str) {
	if (str.size() != 1)
		return false;
	unsigned char c = static_cast<unsigned char>(str[0]);
	return (c <= 127 && !std::isdigit(c));
}

static bool isInt(const std::string &str, int &out) {
	if (str.empty())
		return false;
	char *end;
	errno = 0;
	long val = std::strtol(str.c_str(), &end, 10);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || val > std::numeric_limits<int>:: max() || val < std::numeric_limits<int>::min())
		return false;
	out = static_cast<int>(val);
	return true;
}

static bool isFloat(const std::string &str, float &out) {
	if (str.empty())
		return false;
	char *end;
	errno = 0;
	float val = std::strtof(str.c_str(), &end);
	if (end == str.c_str())
		return false;
	if (*end != 'f' || end[1] != '\0')
		return false;
	if (errno == ERANGE || val > std::numeric_limits<float>::max() || val < std::numeric_limits<float>::lowest())
		return false;
	out = val;
	return true;
}

static bool isDouble(const std::string &str, double &out) {
	if (str.empty())
		return false;
	char *end;
	errno = 0;
	double val = std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || val > std::numeric_limits<double>::max() || val < std::numeric_limits<double>::lowest())
		return false;
	out = val;
	return true;
}

void ScalarConverter::convert(std::string literal) {
	if (print_pseudo_literals(literal))
		return ;
	char c;
	int i;
	float f;
	double d;
	if (isChar(literal)) {
		c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}
	if (isInt(literal, i)) {
		
	}
}

ScalarConverter::~ScalarConverter() {
	
}