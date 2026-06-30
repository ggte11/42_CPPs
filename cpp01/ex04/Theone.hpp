#ifndef THEONE_HPP
# define THEONE_HPP


# include <string>
# include <cstdlib>
#include <fstream>
# include <iostream>
# include <cstring>
#include <iomanip>

void find_replace(std::fstream &file, std::fstream &new_file,
	std::string to_find, std::string to_replace);


#endif