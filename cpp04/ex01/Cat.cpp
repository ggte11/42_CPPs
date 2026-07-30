#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default contructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other.type), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		type = other.type;
		*brain = *other.brain;
	}
	return	*this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
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