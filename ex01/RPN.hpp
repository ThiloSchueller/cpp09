/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:25:23 by tschulle          #+#    #+#             */
/*   Updated: 2026/06/03 14:25:28 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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