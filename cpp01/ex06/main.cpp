#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string level;

	std::cout << "Choose an option!\n";
	std::cout << "DEBUG:\n";
	std::cout << "INFO:\n";
	std::cout << "WARNING:\n";
	std::cout << "ERROR:\n\n";

	while (getline(std::cin, level)) {
		harl.complain(level);
		break ;
	}
	return 0;
}