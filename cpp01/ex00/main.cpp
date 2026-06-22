#include "Zombie.hpp"

int main() {
	std::cout << "Chump is created on the stack" << std::endl;
	randomChump("Chump");
	std::cout << "Dave is created on the heap" << std::endl;
	Zombie *zombie = newZombie("STEVE");
	zombie->announce();
	delete zombie;
	return 0;
}