#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::applyOperation(char op) {
	if (_stack.size() < 2)
		throw std::runtime_error("Error: insufficient operands");
	int right = _stack.top();
	_stack.pop();
	int left = _stack.top();
	_stack.pop();
	switch (op) {
		case '+':
			return _stack.push(left + right);
		case '-':
			return _stack.push(left - right);
		case '*':
			return _stack.push(left * right);
		case '/':
			if (right == 0)
				throw std::runtime_error("Error: can't divide by 0");
			return _stack.push(left / right);
		default:
			throw std::runtime_error("Error: invalid operator");
	}
}

void RPN::calculate(const std::string &expression) {
	while (!_stack.empty())
		_stack.pop();
	std::istringstream input(expression);
	std::string token;
	while (input >> token) {
		if (token.length() != 1)
			throw std::runtime_error("Error: invalid token");
		char character = token[0];
		if (character >= '0' && character <= '9')
			_stack.push(character - '0');
		else if (character == '+' || character == '-' || character == '*' || character == '/')
			applyOperation(character);
		else
			throw std::runtime_error("Error: invalid operator");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	std::cout << _stack.top() << std::endl;
}