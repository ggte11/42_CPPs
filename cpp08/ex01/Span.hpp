#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _nums;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int num);
		void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#endif