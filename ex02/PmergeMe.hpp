#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe {
private:

public:
	/* Constructors & Destructors */
	PmergeMe();
	PmergeMe(char** argv);
	PmergeMe(const PmergeMe& src);
	PmergeMe(PmergeMe&& src);
	~PmergeMe();

	/* Member Functions */

	/* Basic Operators */
	PmergeMe& operator=(const PmergeMe& src);
	PmergeMe& operator=(PmergeMe&& src);

	/* Getters & Setters */

};

#endif // PMERGEME_HPP