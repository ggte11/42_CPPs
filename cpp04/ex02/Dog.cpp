#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default contructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other.type) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return	*this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const{
	std::cout << "Meaww Meaww" << std::endl;
}

std::string Dog::getIdeas(int i) const {
	return (brain->getIdeas(i));
}

void Dog::setIdeas(int i, std::string idea) {
	brain->setIdeas(i, idea);
}