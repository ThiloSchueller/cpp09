#include "RPN.hpp"

/* Constructors & Destructors */
RPN::RPN(std::string& term)
{
	char c;
	std::string line;
	std::stringstream args(term);
	while (getline(args, line, ' '))
	{
		if (line.length() != 1)
			throw RpnError();
		c = line.at(0);
		validateChar(c);
		_term.push_back(c);
	}

	for (char c : _term)
	{
		std::cout << c << " ";
	}

}


RPN::RPN()
{
}

RPN::RPN(const RPN& src)
{
	(void)src;
}

RPN::RPN(RPN&& src)
{
	(void)src;
}

RPN::~RPN()
{
}

/* Member Functions */

/* Basic Operators */
RPN& RPN::operator=(const RPN& src)
{
	if (this != &src)
	{

	}
	return *this;
}

RPN& RPN::operator=(RPN&& src)
{
	if (this != &src)
	{

	}
	return *this;
}

/* Getters & Setters */
const char* RPN::RpnError::what() const noexcept
{
	return ("Error");
}

void RPN::validateChar(char c)
{
	if (!((std::isdigit(c)) || c == '+' || c == '-' || c == '*' || c == '/'))
		throw RpnError();
}