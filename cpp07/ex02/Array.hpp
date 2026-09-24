#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstring>

template<typename T>
class Array
{
	private:
		T *arr;
		unsigned int size;
	public:
		Array();
		~Array();
};

#endif