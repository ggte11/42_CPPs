#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	public:
		int _i;
		std::string _str;
		Data(int i, std::string str);
};

std::ostream &operator<<(std::ostream &out, const Data &obj);

#endif