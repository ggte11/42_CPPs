#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		this->_data = other._data;
	return *this;
}

std::string BitcoinExchange::trim(const std::string &s) {
	const std::string ws = " \t\r\n";
	std::string::size_type first = s.find_last_not_of(ws);
	if (first == std::string::npos)
		return "";
	std::string::size_type last = s.find_last_not_of(ws);
	return s.substr(first, last - first + 1);
}

bool BitcoinExchange::isValidDate(const std::string &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::tm tm;
	std::memset(&tm, 0, sizeof(tm));
	char *end = strptime(date.c_str(), "%Y-%m-%d", &tm);
	if (end == NULL || *end != '\0')
		return false;
	tm.tm_isdst = -1;
	if (std::mktime(&tm) == static_cast<std::time_t>(-1))
		return false;
	char buf[11];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);
	return date == buf;
}

bool BitcoinExchange::parseValue(const std::string &str, float &out) {
	if (str.empty())
		return false;
	char *end;
	const char *start = str.c_str();
	errno = 0;
	double val = std::strtod(start, &end);
	if (end == start || *end != '\0' || errno == ERANGE)
		return false;
	if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
		return false;
	out = static_cast<float>(val);
	return true;
}

float BitcoinExchange::getRate(const std::string &date) const {
	std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
	if (it != _data.end() && it->first == date)
		return it->second;
	if (it == _data.begin())
		throw std::runtime_error("Error: no rate available for this date.");
	it--;
	return it->second;
}