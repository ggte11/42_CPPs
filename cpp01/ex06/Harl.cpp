#include "Harl.hpp"

const std::string Harl::types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl() {}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (types[i] == level) {
			switch (i) {
				case (0):
				std::cout << "[ DEBUG ]" << std::endl;
				debug();
				std::cout << std::endl;
				case (1):
				std::cout << "[ INFO ]" << std::endl;
				info();
				std::cout << std::endl;
				case (2):
				std::cout << "[ WARNING ]" << std::endl;
				warning();
				std::cout << std::endl;
				case (3):
				std::cout << "[ ERROR ]" << std::endl;
				error();
				break ;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]";
}
