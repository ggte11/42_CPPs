#include "Zombie.hpp"

int main() {
	randomChump("Chump");
	Zombie *zombie = newZombie("STEVE");
	zombie->announce();
	delete zombie;
	return 0;
}