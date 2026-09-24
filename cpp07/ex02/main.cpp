#include "iter.hpp"

void printInt(int const &nbr) {
	std::cout << nbr << " ";
}

void increment(int &n) {
	n++;
}

void printString(const std::string &s) {
	std::cout << s << " ";
}

void addSuffix(std::string &s) {
	s += "!";
}

void printDouble(const double &d) {
	std::cout << d << " ";
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	const std::size_t nNumbers = sizeof(numbers) / sizeof(numbers[0]);
	std::cout << "numbers before: ";
	iter(numbers, nNumbers, printInt);
	std::cout << std::endl;
	iter(numbers, nNumbers, increment);
	std::cout << "numbers after increment: ";
	iter(numbers, nNumbers, printInt);
	std::cout << std::endl;

	std::string words[] = {"hello", "template", "world"};
	const std::size_t nWords = sizeof(words) / sizeof(words[0]);
	iter(words, nWords, addSuffix);
	std::cout << "words after addSuffix: ";
	iter(words, nWords, printString);
	std::cout << std::endl;

	const double values[] = {3.14, 2.71, 1.41};
	const std::size_t nValues = sizeof(values) / sizeof(values[0]);
	std::cout << "const values: ";
	iter(values, nValues, printInt);
	std::cout << std::endl;
	return 0;
}