#include "Span.hpp"

Span::Span(unsigned int N) : _size(N) {
	_nums.reserve(N);
}

Span::Span(const Span &other) : _size(other._size) {
	_nums.reserve(_size);
	for (unsigned int i = 0; i < other._nums.size(); i++)
		_nums.push_back(other._nums[i]);
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_nums = other._nums;
		_size = other._size;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_nums.size() >= _size)
		throw std::length_error("Span is full");
	_nums.push_back(num);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) {
	for (std::vector<int>::const_iterator it = begin; it != end; ++it)
		addNumber(*it);
}

unsigned int Span::shortestSpan() const {
	if (_nums.size() < 2)
		throw std::length_error("Not enough numbers on Span");
	std::vector<int> tmp = _nums;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for (std::size_t i = 2; i < tmp.size(); i++) {
		unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan() const {
	if (_nums.size() < 2)
		throw std::length_error("Not enough numbers on Span");
	std::vector<int> tmp = _nums;
	std::sort(tmp.begin(), tmp.end());
	return static_cast<unsigned int>(tmp.back() - tmp.front());
}