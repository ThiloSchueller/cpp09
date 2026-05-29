#include "BitcoinExchange.hpp"

/* Constructors & Destructors */
BitcoinExchange::BitcoinExchange()
{
	std::ifstream in("data.csv");
	if (!in)
	{
		throw BitcoinExchange::CantOpenData();
	}
	readDataCsv(in);

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

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	if (!s.empty() && it == s.end())
		return true;
	return false;
}

int BitcoinExchange::validateKey(std::string& key)
{
	std::stringstream ss(key);
	int year, month, day;
	std::string temp, re;

	getline(ss, temp, '-');
	if (temp.length() != 4 || !is_number(temp))
		throw BitcoinExchange::BadInput(key);
	year = std::stoi(temp);
	re = temp;

	getline(ss, temp, '-');
	if (temp.length() != 2 || !is_number(temp))
		throw BitcoinExchange::BadInput(key);
	month = std::stoi(temp);
	re += temp;

	getline(ss, temp);
	if (temp.length() != 2 || !is_number(temp))
		throw BitcoinExchange::BadInput(key);
	day = std::stoi(temp);
	re += temp;

	if (month < 1 || month > 12)
		throw BitcoinExchange::BadInput(key);
	int daysPerMonth[12] = { 31, 28 ,31 ,30 ,31, 30, 31, 31, 30, 31, 30, 31 };
	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (leap)
		daysPerMonth[1] = 29;
	if (day < 1 || day > daysPerMonth[month - 1])
		throw BitcoinExchange::BadInput(key);
	return (stoi(re));
}

double  BitcoinExchange::validateValue(std::string& value)
{
	std::stringstream ss(value);
	std::string temp;
	double number;

	if (value != "" && value[0] == '-')
		throw NotAPositiveNumber();
	getline(ss, temp, '.');
	if (!is_number(temp))
		throw BitcoinExchange::BadInput(value);
	if (getline(ss, temp) && !is_number(temp))
		throw BitcoinExchange::BadInput(value);
	number = stod(value);
	return (number);
}

void BitcoinExchange::readDataCsv(std::ifstream& in)
{
	std::string captions;
	getline(in, captions);
	if (captions != "date,exchange_rate")
		throw BitcoinExchange::BadColumns();
	std::string key;
	std::string value;
	int date;
	double exchangeRate;
	while (std::getline(in, key, ',') && std::getline(in, value))
	{
		date = validateKey(key);
		exchangeRate = validateValue(value);
		_dataMap.insert(std::pair(date, exchangeRate));
	}
}

double BitcoinExchange::calc(int date, double amount)
{
	auto it = _dataMap.upper_bound(date);

	if (it != _dataMap.begin())
		--it;
	else
		it = _dataMap.begin();
	return (it->second * amount);
}


void BitcoinExchange::execute(char** argv)
{
	std::ifstream in(argv[1]);
	if (!in)
	{
		throw BitcoinExchange::CantOpenData();
	}
	std::string captions;
	getline(in, captions);
	if (captions != "date | value")
		throw BitcoinExchange::BadColumns();
	std::string key, value, stick, line;
	int date;
	double amount;
	while (std::getline(in, line))
	{
		try
		{
			std::stringstream ss(line);
			std::getline(ss, key, ' ');
			if (!(std::getline(ss, stick, ' ')))
				stick = "";
			if (!(std::getline(ss, value)))
				value = "";
			date = validateKey(key);
			if (stick != "|")
				throw BitcoinExchange::BadInput(stick);
			amount = validateValue(value);
			if (amount > 1000)
				throw BitcoinExchange::TooLargeANumber();
			std::cout << key << " => " << value << " : " << calc(date, amount) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
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
	return (msg.c_str());
}

const char* BitcoinExchange::TooLargeANumber::what() const noexcept
{
	return ("Error: too large a number");
}

const char* BitcoinExchange::BadColumns::what() const noexcept
{
	return ("Error: unexpected first line for column labeling");
}