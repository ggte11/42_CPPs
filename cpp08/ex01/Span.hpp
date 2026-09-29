#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> nums;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int num);
};

#endif