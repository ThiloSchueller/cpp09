#include "BitcoinExchange.hpp"

/* Constructors & Destructors */
BitcoinExchange::BitcoinExchange()
{
	std::ifstream in("data.csv");
	if (!in)
	{
		throw BitcoinExchange::CantOpenData();
	}

	std::string captions;
	getline(in, captions);
	std::string key;
	std::string value;
	while (!in.eof())
	{
		getline(in, key, ',');
		validateKey(key);
		getline(in, value);
		//validateValue(value);
		//transform to double
		_dataMap.emplace(key, std::stod(value));
		std::cout << key << "\n" << std::endl;
	}
	for (auto it = _dataMap.begin(); it != _dataMap.end(); it++)
	{
		std::cout << it->first << it->second << "\n" << std::endl;
	}
	// std::string key, value;

	// while (std::getline(in, key, ',') && std::getline(in, value))
	// {
	// 	_dataMap.emplace(key, value);
	// }

	// for (const auto& it : _dataMap)
	// {
	// 	std::cout << it.first << " " << it.second << "\n";
	// }

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	(void)src;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange&& src)
{
	(void)src;
}

BitcoinExchange::~BitcoinExchange()
{
}

/* Member Functions */

/* Basic Operators */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
	{

	}
	return *this;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange&& src)
{
	if (this != &src)
	{

	}
	return *this;
}

/* Getters & Setters */

void BitcoinExchange::execute(std::string& input)
{
	(void)input;
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	if (!s.empty() && it == s.end())
		return true;
	return false;
}

void BitcoinExchange::validateKey(std::string& key)
{
	std::stringstream ss(key);
	int year, month, day;
	std::string temp;
	getline(ss, temp, '-');
	if (temp.length() != 4 || !is_number(temp))
		throw BitcoinExchange::BadInput();
	year = std::stoi(temp);
	getline(ss, temp, '-');
	if (temp.length() != 2 || !is_number(temp))
		throw BitcoinExchange::BadInput();
	month = std::stoi(temp);
	getline(ss, temp);
	if (temp.length() != 2 || !is_number(temp))
		throw BitcoinExchange::BadInput();
	day = std::stoi(temp);

	if (month < 1 || month > 12)
		throw BitcoinExchange::BadInput();
	int daysPerMonth[12] = { 31, 28 ,31 ,30 ,31, 30, 31, 31, 30, 31, 30, 31 };
	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (leap)
		daysPerMonth[1] = 29;
	if (day < 1 || day > daysPerMonth[month - 1])
		throw BitcoinExchange::BadInput();

}


const char* BitcoinExchange::CantOpenData::what() const noexcept
{
	return ("Can't find or open data.csv");
}


const char* BitcoinExchange::CantOpenFile::what() const noexcept
{
	return ("Error: Could not open file.");
}

const char* BitcoinExchange::NotAPositiveNumber::what() const noexcept
{
	return ("Error: not a positive number.");
}

const char* BitcoinExchange::BadInput::what() const noexcept
{
	return ("Error: bad input => ");
}

const char* BitcoinExchange::TooLargeANumber::what() const noexcept
{
	return ("Error: too large a number");
}