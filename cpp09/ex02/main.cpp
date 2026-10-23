#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: too many parameters." << std::endl;
		return 1;
	}
	try
	{
		PmergeMe sorter;
		sorter.sort(argc ,argv);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}