#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid argument count. Usage: ./btc input.txt" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btcExchange;
		btcExchange.execute(argv);
	}
	catch (BitcoinExchange::BadInput& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}