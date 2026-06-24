#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	Zombie::name = name;
}

Zombie::Zombie() {};

Zombie::~Zombie() {
	std::cout << this->name << " has been destroyed..." << std::endl; 
}

void	Zombie::setName(std::string name) {
	this->name = name;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}