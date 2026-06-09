#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

class PmergeMe {
private:
	std::vector<std::pair<int, int>> _v;
	std::deque<int> _d;
public:
	/* Constructors & Destructors */
	PmergeMe() = delete;
	PmergeMe(int argc, char** argv);
	PmergeMe(const PmergeMe& src) = delete;
	PmergeMe(PmergeMe&& src) = delete;
	~PmergeMe();

	/* Member Functions */
	void sort_v(int n);
	int jakobstahl(int k);

	/* Basic Operators */
	PmergeMe& operator=(const PmergeMe& src) = delete;
	PmergeMe& operator=(PmergeMe&& src) = delete;

	/* Getters & Setters */

};

#endif // PMERGEME_HPP