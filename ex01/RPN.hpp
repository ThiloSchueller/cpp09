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
	RPN();
	RPN(std::string& term);
	RPN(const RPN& src);
	RPN(RPN&& src);
	~RPN();

	/* Member Functions */

	/* Basic Operators */
	RPN& operator=(const RPN& src);
	RPN& operator=(RPN&& src);

	/* Getters & Setters */
	void validateChar(char c);
	class RpnError : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
};

#endif // RPN_HPP