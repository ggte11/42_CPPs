#include "Fixed.hpp"

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	this->val = val << bits;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->val = roundf(val *(1 << bits));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assigment operator called" << std::endl;
	val = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (this->val);
}

void Fixed::setRawBits(int const raw) {
	this->val = raw;
}

