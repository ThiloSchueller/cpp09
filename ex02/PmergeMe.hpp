#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Node.hpp"

class PmergeMe {
private:
	std::vector<Node> _v;
	std::deque<int> _d;
public:
	/* Constructors & Destructors */
	PmergeMe() = delete;
	PmergeMe(int argc, char** argv);
	PmergeMe(const PmergeMe& src) = delete;
	PmergeMe(PmergeMe&& src) = delete;
	~PmergeMe();

	/* Member Functions */
	std::vector<Node> sort_v(std::vector<Node> v);
	int jakobstahl(int k);
	int binarySearch(int low, int high, Node& item, std::vector<Node>& v) const;

	/* Basic Operators */
	PmergeMe& operator=(const PmergeMe& src) = delete;
	PmergeMe& operator=(PmergeMe&& src) = delete;

	/* Getters & Setters */
	int getNumberOfComparison() const;
	int getNodeValue(int i) const;
	const Node& getNode(int i) const;
	int getSize() const;
};

std::ostream& operator<<(std::ostream& o, const PmergeMe& src);

#endif // PMERGEME_HPP