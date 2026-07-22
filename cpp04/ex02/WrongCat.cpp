#include "WrongCat.hpp"

WrongCat::WrongCat() : Animal("WrongCat") {
	std::cout << "WrongCat default contructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : Animal(other.type) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		this->type = other.type;
	return	*this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
	std::cout << "strange Meaww Meaww" << std::endl;
}