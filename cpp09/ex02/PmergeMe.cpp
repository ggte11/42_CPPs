#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(int argc, char **argv) {
	_vector.clear();
	_deque.clear();
	if (argc < 2)
		return false;
	for (int i = 1; i < argc; i++) {
		std::istringstream stream(argv[i]);
		int nb;
		stream >> nb;
		if (stream.fail() || !stream.eof())
			return false;
		if (nb <= 0)
			return false;
		_vector.push_back(nb);
		_deque.push_back(nb);
	}
	return true;
}

void PmergeMe::sort(int argc,char **argv) {
	if (!isValidInput(argc, argv))
		throw std::runtime_error("Error: invalid input.");
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	sortVector();
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector() {
	
}

void PmergeMe::sortDeque() {

}