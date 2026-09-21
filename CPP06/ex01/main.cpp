#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data(42, "hello");
	Data *ptr = &data;
	std::cout << "original ptr: " << ptr << std::endl;
	std::cout << "original data: " << *ptr << std::endl;

	uintptr_t raw = Serializer::serialize(ptr);
	Data *restored = Serializer::deserialize(raw);
	std::cout << "raw: " << raw << std::endl;
	std::cout << "restored ptr: " << restored << std::endl;
	std::cout << "restored data: " << *restored << std::endl;
	if (ptr == restored)
		std::cout << "same pointer" << std::endl;
	else
		std::cout << "different pointer" << std::endl;

	Data other(7, "world");
	uintptr_t raw2 = Serializer::serialize(&other);
	Data *restored2 = Serializer::deserialize(raw2);
	std::cout << "other ptr: " << &other << std::endl;
	std::cout << "restored2 ptr: " << restored2 << std::endl;
	std::cout << "other data: " << other << std::endl;
	std::cout << "restored2 data: " << *restored2 << std::endl;
	if (&other == restored2)
		std::cout << "same pointer again" << std::endl;
	else
		std::cout << "different pointer again" << std::endl;
	return 0;
}