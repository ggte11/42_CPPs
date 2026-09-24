#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T, typename F>
void iter(T *array, const int len, F func) {
	if (!array)
		return ;
	for (int i = 0; i < len; i++) {
		func(array[i]);
	}
}

#endif