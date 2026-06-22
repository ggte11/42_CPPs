#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie	*novo = new Zombie(name);
	return novo;
}