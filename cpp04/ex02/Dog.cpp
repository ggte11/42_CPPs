#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default contructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other.type), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		delete brain;
		type = other.type;
		brain = new Brain(*other.brain);
	}
	return	*this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const{
	std::cout << "Barkk Barkk" << std::endl;
}

std::string Dog::getIdeas(int i) const {
	return (brain->getIdeas(i));
}

void Dog::setIdeas(int i, std::string idea) {
	brain->setIdeas(i, idea);
}