#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavy");
	FragTrap frag("Fraggy");

	clap.attack("target 1");
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << std::endl;
	scav.attack("target 2");
	scav.guardGate();
	scav.takeDamage(20);
	scav.beRepaired(5);

	std::cout << std::endl;
	frag.attack("target 3");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.highFivesGuys();

	return 0;
}