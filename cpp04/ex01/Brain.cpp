#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default contructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return	*this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}


std::string Brain::getIdeas(int i) const {
	return (ideas[i]);
}

void Brain::setIdeas(int i, std::string idea) {
	ideas[i] = idea;
}