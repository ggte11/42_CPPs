#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	_name = "fragtrap";
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "FragTrap default constructor called" << std::endl;
	_name = name;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Copy assigment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_HitPoints = other._HitPoints;
		this->_EnergyPoints = other._EnergyPoints;
		this->_AttackDamage = other._AttackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (_HitPoints == 0) {
		std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
		return ;
	}
	if (_EnergyPoints > 0) {
		std::cout << "FragTrap " << _name << " attacks " << target << " dealing " << _AttackDamage << " points of damage!" << std::endl;
		_EnergyPoints--;
	}
	else {
		std::cout << "FragTrap " << _name << " has no energy left to attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	if (_HitPoints == 0) {
		std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name <<  " is requesting positive high fives!" << std::endl;
}