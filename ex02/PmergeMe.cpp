#include "PmergeMe.hpp"

/* Constructors & Destructors */
auto print = [](const int& n) { std::cout << ' ' << n; };

PmergeMe::PmergeMe(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		_v.push_back(std::make_pair(std::stoi(argv[i]), 0));
	}
	sort_v(_v.size());
	std::for_each(_v.begin(), _v.end(), [](const int& n) { std::cout << ' ' << n; }); //overload << ?
}

void PmergeMe::sort_v(int n)
{
	for (int i = 0; i + 1 < n; i = i + 2)
	{
		if (_v[i].first > _v[i + 1].first)
			std::swap(_v[i], _v[i + 1]);
		_v[i].second = i + 1;
		_v[i + 1].second = i + 1;
	}
}

int jakobstahl(int k)
{
	int arr[] = { 1, 1, 3, 5, 11, 21, 43, 85 };
	return arr[k];
}

PmergeMe::~PmergeMe()
{
}

