#include "RPN.hpp"

/* Constructors & Destructors */
RPN::RPN(std::string& term)
{
	char c;
	std::string line;
	std::stringstream args(term);
	while (getline(args, line, ' '))
	{
		if (line.empty())
			continue;
		if (line.length() != 1)
			throw RpnError();
		c = line[0];
		if (std::isdigit(c))
			_term.push(c - '0');
		else
			calc(c);
	}
	if (_term.size() != 1)
		throw RpnError();
	std::cout << _term.top() << std::endl;
}

RPN::~RPN()
{
}

/* Member Functions */

/* Basic Operators */

/* Getters & Setters */
const char* RPN::RpnError::what() const noexcept
{
	return ("Error");
}

const char* RPN::DivisionByZeroError::what() const noexcept
{
	return ("Error: Division by Zero");
}

void RPN::calc(char c)
{
	if (_term.empty())
		throw RpnError();
	int a = _term.top();
	_term.pop();

	if (_term.empty())
		throw RpnError();
	int b = _term.top();
	_term.pop();

	switch (c)
	{
		case ('+'):
			_term.push(b + a);
			break;
		case ('-'):
			_term.push(b - a);
			break;
		case ('/'):
			if (a == 0)
				throw DivisionByZeroError();
			_term.push(b / a);
			break;
		case ('*'):
			_term.push(b * a);
			break;
		default:
			throw RpnError();
	}
}