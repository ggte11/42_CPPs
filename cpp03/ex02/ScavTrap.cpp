#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "scavtrap";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	GuardMode = false;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	_name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	GuardMode = false;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_HitPoints = other._HitPoints;
		this->_EnergyPoints = other._EnergyPoints;
		this->_AttackDamage = other._AttackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (_HitPoints == 0) {
		std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
		return ;
	}
	if (_EnergyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << " dealing " << _AttackDamage << " points of damage!" << std::endl;
		_EnergyPoints--;
	}
	else {
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	if (GuardMode == false)
		std::cout << "ScavTrap " << _name << " is in GateKeeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is no longer in GateKeeper mode!" << std::endl;
	GuardMode = !GuardMode;
}