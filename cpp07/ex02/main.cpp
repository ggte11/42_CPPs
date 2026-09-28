#include "Array.hpp"

int main(void)
{
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); ++i)
		a[i] = i + 1;

	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	Array<int> b(a);
	b[0] = 42;
	b[1] = 5;

	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;
	std::cout << "b[1] = " << b[1] << std::endl;

	Array<int> c;
	std::cout << "c.size() = " << c.size() << std::endl;
	std::cout << "a.size() = " << a.size() << std::endl;

	Array<char> d(3);
	d[0] = 'A';
	d[1] = 'B';
	d[2] = 'C';

	std::cout << "d: ";
	for (unsigned int i = 0; i < d.size(); ++i)
		std::cout << d[i] << " ";
	std::cout << std::endl;
	try
	{
		std::cout << d[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}