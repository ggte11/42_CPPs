#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("claptrap"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;

}

ClapTrap::ClapTrap(std::string name) : _name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assigment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_HitPoints = other._HitPoints;
		this->_EnergyPoints = other._EnergyPoints;
		this->_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_HitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
		return ;
	}
	if (_EnergyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << " dealing " << _AttackDamage << " points of damage!" << std::endl;
		_EnergyPoints--;
	}
	else {
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_HitPoints == 0) {
		std::cout << "ClapTrap " << _name << "is already destryed!" << std::endl;
		return ;
	}
	if (_HitPoints > amount) {
		std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage!" << std::endl;
		_HitPoints -= amount;
	}
	else {
		_HitPoints = 0;
		std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_HitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return ;
	}
	if (_EnergyPoints > 0) {
		if (_HitPoints < 10) {
			std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points of health!" << std::endl;
			if (_HitPoints + amount <= 10) {
				_HitPoints += amount;
			}
			else
				_HitPoints = 10;
			_EnergyPoints--;
		}
		else
			std::cout << "ClapTrap " << _name << "is already fully repaired!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
}