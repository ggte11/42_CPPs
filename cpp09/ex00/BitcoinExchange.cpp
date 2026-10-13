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

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &s) {
	const std::string ws = " \t\r\n";
	std::string::size_type first = s.find_first_not_of(ws);
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

void BitcoinExchange::loadDatabase(const std::string &csvPath) {
	std::ifstream file(csvPath.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream stream(line);
		std::string date;
		std::string rateText;
		if (!std::getline(stream, date, ',') || !std::getline(stream, rateText))
			continue;
		date = trim(date);
		rateText = trim(rateText);
		float rate;
		if (isValidDate(date) && parseValue(rateText, rate))
			_data[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string &inputPath) {
	std::ifstream file(inputPath.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream stream(line);
		std::string date;
		std::string valueText;
		if (!std::getline(stream, date, '|') || !std::getline(stream, valueText)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = trim(date);
		valueText = trim(valueText);
		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value;
		if (!parseValue(valueText, value)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			float rate = getRate(date);

			std::cout << date << " => " << value
				<< " = " << value * rate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}