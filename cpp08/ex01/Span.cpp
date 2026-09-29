#include "Span.hpp"

Span::Span(unsigned int N) : _size(N) {
	nums.reserve(N);
}

Span::Span(const Span &other) : _size(other._size) {
	nums.reserve(_size);
	for (unsigned int i = 0; i < other.nums.size(); i++)
		nums.push_back(other.nums[i]);
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		nums = other.nums;
		_size = other._size;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	
}