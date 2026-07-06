#include "Fixed.hpp"

int main() {
	Fixed a;
	a.setRawBits(42);
	Fixed b(a);
	Fixed c;

	c = b;
	a.setRawBits(5);
	std::cout << "a = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b.getRawBits() << std::endl;
	std::cout << "c = " << c.getRawBits() << std::endl;
	return 0;
}