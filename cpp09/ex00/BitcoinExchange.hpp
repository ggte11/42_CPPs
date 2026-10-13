#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <cstring>
#include <stdexcept>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
	static std::string trim(const std::string &s);
	static bool isValidDate(const std::string &date);
	static bool parseValue(const std::string &str, float &out);
	float getRate(const std::string &date) const;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	void loadDatabase(const std::string &csvPath);
	void processInput(const std::string &inputPath);
};

#endif