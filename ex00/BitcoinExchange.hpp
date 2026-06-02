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
	std::map<int, double> _dataMap;
public:
	/* Constructors & Destructors */
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src) = delete;
	BitcoinExchange(BitcoinExchange&& src) = delete;
	~BitcoinExchange();

	/* Member Functions */

	/* Basic Operators */
	BitcoinExchange& operator=(const BitcoinExchange& src) = delete;
	BitcoinExchange& operator=(BitcoinExchange&& src) = delete;

	/* Getters & Setters */
	void readDataCsv(std::ifstream& in);
	void execute(char** argv);
	double calc(int date, double amount);
	int validateKey(std::string& key);
	double validateValue(std::string& value);
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
	private:
		std::string msg;
	public:
		BadInput(const std::string& msg)
			: msg("Error: bad input => " + msg) {
		};
		const char* what() const noexcept override;
	};
	class TooLargeANumber : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	class BadColumns : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
};

#endif // BITCOINEXCHANGE_HPP