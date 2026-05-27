#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
// #include <utility>


class BitcoinExchange {
private:
	std::map<std::string, double> _dataMap;
public:
	/* Constructors & Destructors */
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange(BitcoinExchange&& src);
	~BitcoinExchange();

	/* Member Functions */

	/* Basic Operators */
	BitcoinExchange& operator=(const BitcoinExchange& src);
	BitcoinExchange& operator=(BitcoinExchange&& src);

	/* Getters & Setters */
	void execute(std::string& input);
	void validateKey(std::string& key);
	void validateValue(std::string& value);
	class CantOpenData : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	class CantOpenFile : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	class NotAPositiveNumber : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	class BadInput : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	class TooLargeANumber : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
};

#endif // BITCOINEXCHANGE_HPP