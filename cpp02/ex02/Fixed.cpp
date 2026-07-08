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
	std::cout << "Copy assignment operator called" << std::endl;
	val = copy.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called" << std::endl;
	return (this->val);
}

void Fixed::setRawBits(int const raw) {
	this->val = raw;
}

float Fixed::toFloat() const{
	return (static_cast<float>(this->val) / (1 << bits));
}

int Fixed::toInt() const {
	return (val >> bits);
}

bool Fixed::operator>(const Fixed &other) const {
	return (val > other.val);
}

bool Fixed::operator<(const Fixed &other) const {
	return (val < other.val);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (val >= other.val);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (val <= other.val);
}

bool Fixed::operator==(const Fixed &other) const {
	return (val == other.val);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (val != other.val);
}

Fixed Fixed::operator+(const Fixed &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++(void) {
	++val;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed prev(*this);
	val++;
	return prev;
}

Fixed& Fixed::operator--(void) {
	--val;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed prev(*this);
	val--;
	return prev;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}