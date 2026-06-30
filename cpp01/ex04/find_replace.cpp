#include "Theone.hpp"

void find_replace(std::fstream &file, std::fstream &new_file, std::string to_find, std::string to_replace) {
	if (to_find.empty())
		return ;
	std::string line;
	while (std::getline(file, line)) {
		std::string::size_type pos = 0;
		while ((pos = line.find(to_find, pos)) != std::string::npos) {
			line.erase(pos, to_find.length());
			line.insert(pos, to_replace);
			pos += to_replace.length();
		}
		new_file << line;
		if (!file.eof())
			new_file << '\n';
	}
}