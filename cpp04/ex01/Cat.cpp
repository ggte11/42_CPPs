#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default contructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		this->type = other.type;
	return	*this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meaww Meaww" << std::endl;
}

std::string Cat::getIdeas(int i) const {
	return (brain->getIdeas(i));
}

void Cat::setIdeas(int i, std::string idea) {
	brain->setIdeas(i, idea);
}