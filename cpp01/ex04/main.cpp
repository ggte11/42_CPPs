#include "Theone.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Invalid number of arguments";
		return 1;
	}
	if (!argv[2][0]) {
		std::cout << "s1 cannot be empty" << std::endl;
		return 1;
	}
	std::fstream file(argv[1], std::ios::in);
	if (!file.is_open()) {
		std::cout << "Error: cannot open input file" << std::endl;
		return 1;
	}
	std::string outp_name = std::string(argv[1]) + ".replace";
	std::fstream new_file(outp_name.c_str(), std::ios::out | std::ios::trunc);
	if (!new_file.is_open()) {
		std::cout << "Error: cannot open output file" << std::endl;
		return 1;
	}
	find_replace(file, new_file, argv[2], argv[3]);
	file.close();
	new_file.close();
	return 0;
}