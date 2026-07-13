#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Claptingon");

	a.attack("Bob");
	a.takeDamage(3);
	b.attack("ScaviTrone");
	a.beRepaired(2);
	b.takeDamage(5);
	b.beRepaired(4);
	std::cout << std::endl;

	ScavTrap s1;
	ScavTrap s2("ScaviTrone");

	s1.attack("Claptingon");
	s1.takeDamage(20);
	s2.guardGate();
	s1.beRepaired(5);
	s2.attack("Claptingon");
	s2.takeDamage(42);
	s2.beRepaired(10);
	return 0;
}