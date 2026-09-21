#include "Data.hpp"

Data::Data(int nbr, std::string str) {
	_i = nbr;
	_str = str;
}

std::ostream &operator<<(std::ostream &out, const Data &obj) {
	out << "Integer: " << obj._i << "\nString: " << obj._str;
	return out;
}