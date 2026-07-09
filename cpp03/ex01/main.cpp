#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Bob");

	a.attack("Bob");
	a.takeDamage(3);
	b.attack("ClapTrap");
	a.beRepaired(2);
	b.takeDamage(5);
	b.beRepaired(4);
	return 0;
}