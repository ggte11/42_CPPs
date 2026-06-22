#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	Zombie::name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << " has been destroyed..." << std::endl; 
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}