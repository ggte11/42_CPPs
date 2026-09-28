#include "Array.hpp"

template<typename T>Array<T>::Array() : _arr(new T[1]), _size(0) {
	_arr[0] = 0;
}

template<typename T>Array<T>::Array(unsigned int n) : _arr(new T[n]()), _size(n) {}

template<typename T>Array<T>::Array(const Array &other) : _arr(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < size(); i++)
		_arr[i] = other._arr[i];
}

template<typename T>Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		_size = other.size();
		delete[] _arr;
		_arr = new T[_size];
		for (unsigned int i = 0; i < size(); i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template<typename T>Array<T>::~Array() {
	delete[] _arr;
}

template<typename T>unsigned int Array<T>::size() const {
	return _size;
}

template<typename T>T &Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw(std::out_of_range("Index out of bounds"));
	return _arr[index];
}