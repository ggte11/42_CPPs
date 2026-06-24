#include "Zombie.hpp"

int main() {
	std::cout << "Arise Peasants!!!" << std::endl;
	int N = 10;
	Zombie *horde = zombieHorde(N, "CrazyPeasant");
	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}