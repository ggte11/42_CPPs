#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
	private:
		bool GuardMode;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
};

#endif