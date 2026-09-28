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
	if (str.empty() || str[str.size() - 1] != 'f')
		return (false);
	std::string digits = str.substr(0, str.size() - 1);
	if (digits.empty())
		return false;
	char* end;
	errno = 0;
	double val = std::strtod(digits.c_str(), &end);
	if (*end != '\0')
		return false;
	if (errno == ERANGE || val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max())
		return false;
	out = static_cast<float>(val);
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
	if (errno == ERANGE)
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
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return ;
	}
	if (isInt(literal, i)) {
		if (i >= 0 && i <= 127) {
			c = static_cast<char>(i);
			if (std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i);
		if (std::fabs(static_cast<float>(i)) < 1e7f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		return ;
	}
	if (isFloat(literal, f)) {
		if ((roundf(f) == f) && (f >= 0 && f <= 127)) {
			c = static_cast<char>(f);
			if (std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (f >= -2147483648.0f && f < 2147483648.0f)
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f;
		if (std::floor(f) == f && std::fabs(f) < 1e7f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f);
		if (std::floor(f) == f && std::fabs(f) < 1e7f)
			std::cout << ".0";
		std::cout << std::endl;
		return ;
	}
	if (isDouble(literal, d)) {
		if ((d >= 0 && d <= 127) && std::floor(d) == d) {
			c = static_cast<char>(d);
			if (std::isprint(static_cast<unsigned char>(c)))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: impossible" << std::endl;
		if (d >= -2147483648.0 && d < 2147483648.0)
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max()) {
			std::cout << "float: " << static_cast<float>(d);
			if (std::floor(d) == d && std::fabs(d) < 1e7)
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		else
			std::cout << "float: impossible" << std::endl;
		std::cout << "double: " << d;
		if (std::floor(d) == d && std::fabs(d) < 1e16)
			std::cout << ".0";
		std::cout << std::endl;
		return;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	
}