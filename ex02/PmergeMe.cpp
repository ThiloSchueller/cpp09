#include "PmergeMe.hpp"

/* Constructors & Destructors */

PmergeMe::PmergeMe(int argc, char** argv)
	: _n(0)
{
	for (int i = 1; i < argc; i++)
	{
		_v.push_back(Node(argv[i]));
	}
}

void PmergeMe::sort_v(int n, )
{
	std::vector<Node> nv;
	for (int i = 0; i < n; i = i++)
	{
		if (_v[i] < _v[i + 1])
		{
			_v[i].ANode = &_v[i + 1];
			std::swap()
		}
		else
		{
			_v[i + 1].ANode = &_v[i];
		}
		_n++;
	}
}

int PmergeMe::jakobstahl(int k)
{
	int arr[] = { 1, 1, 3, 5, 11, 21, 43, 85 };
	return arr[k];
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::getNumberOfComparison() const
{
	return (_n);
}

int PmergeMe::getNodeValue(int i) const
{
	return(_v[i].value);
}

int PmergeMe::getSize() const
{
	return(_v.size());
}

std::ostream& operator<<(std::ostream& o, const PmergeMe& src)
{
	for (int i = 0; i < src.getSize(); i++)
	{
		o << src.getNodeValue(i) << " ";
	}
	o << std::endl;
	return (o);
}