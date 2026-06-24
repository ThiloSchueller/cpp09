#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Node.hpp"
#include <chrono>

class PmergeMe {
private:
	std::vector<Node> _v;
	std::deque<Node> _d;
public:
	/* Constructors & Destructors */
	PmergeMe() = delete;
	PmergeMe(int argc, char** argv);
	PmergeMe(const PmergeMe& src) = delete;
	PmergeMe(PmergeMe&& src) = delete;
	~PmergeMe();

	/* Member Functions */
	std::vector<Node> sort_v(const std::vector<Node>& v) const;
	std::deque<Node> sort_d(const std::deque<Node>& d) const;
	int jakobstahl(int k) const;
	int binarySearch_v(int low, int high, Node& item, std::vector<Node>& v) const;
	int binarySearch_d(int low, int high, Node& item, std::deque<Node>& d) const;

	/* Basic Operators */
	PmergeMe& operator=(const PmergeMe& src) = delete;
	PmergeMe& operator=(PmergeMe&& src) = delete;

	/* Getters & Setters */
	const Node& getNode_v(int i) const;
	const Node& getNode_d(int i) const;
	int getSize_v() const;
	int getSize_d() const;
};

std::ostream& operator<<(std::ostream& o, const PmergeMe& src);

#endif // PMERGEME_HPP