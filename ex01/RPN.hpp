#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <list>
#include <sstream>
#include <stack>

class RPN {
private:
	//std::list<char> _term;
	std::stack<int, std::list<int>> _term;
public:
	/* Constructors & Destructors */
	RPN() = delete;
	RPN(std::string& term);
	RPN(const RPN& src) = delete;
	RPN(RPN&& src) = delete;
	~RPN();

	/* Member Functions */

	/* Basic Operators */
	RPN& operator=(const RPN& src) = delete;
	RPN& operator=(RPN&& src) = delete;

	/* Getters & Setters */
	void calc(char c);
	class RpnError : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	class DivisionByZeroError : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
};

#endif // RPN_HPP