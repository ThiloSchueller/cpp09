#include "PmergeMe.hpp"

static bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	if (!s.empty() && it == s.end())
		return true;
	return false;
}

/* Constructors & Destructors */

PmergeMe::PmergeMe(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
			throw std::exception();
		_v.push_back(Node(argv[i]));
		_v[i - 1].unique_index = i;
	}
	for (int i = 1; i < argc; i++)
	{
		_d.push_back(Node(argv[i]));
		_d[i - 1].unique_index = i;
	}
	std::cout << "Before: " << *this << std::endl;
	std::chrono::steady_clock::time_point begin_v = std::chrono::steady_clock::now();
	_v = sort_v(_v);
	std::chrono::steady_clock::time_point end_v = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point begin_d = std::chrono::steady_clock::now();
	_d = sort_d(_d);
	std::chrono::steady_clock::time_point end_d = std::chrono::steady_clock::now();
	std::cout << "After: " << *this << std::endl;
	std::cout << "Time to process a range of " << _v.size() << " elements with std::vector : " << std::chrono::duration_cast<std::chrono::microseconds>(end_v - begin_v).count() << " [µs]" << std::endl;
	std::cout << "Time to process a range of " << _d.size() << " elements with std::deque : " << std::chrono::duration_cast<std::chrono::microseconds>(end_d - begin_d).count() << " [µs]" << std::endl;
	//std::cout << "Is sorted " << std::is_sorted(_v.cbegin(), _v.cend()) << std::endl;
	//std::cout << "comparisons " << (Node::getNumberOfComparisons()) / 2 << std::endl;
}

std::vector<Node> PmergeMe::sort_v(const std::vector<Node>& v) const
{
	std::vector<Node> av;
	std::vector<Node> bv;
	std::vector<Node> nbv;
	std::vector<Node> nav;
	std::vector<Node> mav;

	if (v.size() == 1)
	{
		return (v);
	}

	// sort v into av and bv and save in a the corresponding b;
	size_t i = 0;
	while (i < v.size() - 1)
	{
		if (v[i] < v[i + 1])
		{
			av.push_back(v[i + 1]);
			bv.push_back(v[i]);
		}
		else
		{
			av.push_back(v[i]);
			bv.push_back(v[i + 1]);
		}
		av.back().index_where_to_find_underlying_b = av.size() - 1;
		i = i + 2;
	}
	if (v.size() % 2 != 0)
	{
		bv.push_back(v[i]);
	}

	// get a sorted a back;
	nav = sort_v(av);

	// mirror to not lose b data
	mav.resize(av.size());
	for (size_t i = 0; i < nav.size(); i++)
	{
		int x = 0;
		for (size_t j = 0; j < av.size(); j++)
		{
			if (nav[i].unique_index == av[j].unique_index)
			{
				x = j;
				break;
			}
		}
		mav[i] = av[x];
	}

	// sort b by ordering with the information and the acutal index of a in v;
	nbv.resize(bv.size());
	for (size_t i = 0; i < mav.size(); i++)
	{
		nbv[i] = bv[mav[i].index_where_to_find_underlying_b];
	}
	if (bv.size() > mav.size())
	{
		nbv[bv.size() - 1] = bv[bv.size() - 1];
	}

	// create main chain by adding smallest b
	// insert b following binary search with jakobsthal priority list into main chain;
	mav.insert(mav.begin(), nbv[0]);
	int k = 2;
	int jakob = jakobstahl(k);
	for (size_t i = 1; i < nbv.size(); i++)
	{
		while (jakob > static_cast<int>(nbv.size()))
			jakob--;
		mav.insert(mav.begin() + binarySearch_v(0, i + jakob - 2, nbv[jakob - 1], mav), nbv[jakob - 1]);
		--jakob;
		if (jakob == jakobstahl(k - 1))
		{
			jakob = jakobstahl(++k);
			if (jakob > static_cast<int>(nbv.size()))
				jakob = static_cast<int>(nbv.size());
		}
	}
	return mav;
}

int PmergeMe::binarySearch_v(int low, int high, Node& item, std::vector<Node>& v) const
{
	if (low > high)
		return low;
	int mid = (low + high) / 2;
	if (v[mid] < item)
	{
		return (binarySearch_v(mid + 1, high, item, v));
	}
	else
	{
		return (binarySearch_v(low, mid - 1, item, v));
	}
}

int PmergeMe::jakobstahl(int k) const
{
	return ((pow(2, k + 1) + pow(-1, k)) / 3);
}

PmergeMe::~PmergeMe()
{
}

const Node& PmergeMe::getNode_v(int i) const
{
	return (_v[i]);
}

int PmergeMe::getSize_v() const
{
	return(_v.size());
}

std::ostream& operator<<(std::ostream& o, const PmergeMe& src)
{
	for (int i = 0; i < src.getSize_v(); i++)
	{
		o << src.getNode_v(i) << " ";
	}
	// std::cout << std::endl;
	// for (int i = 0; i < src.getSize_d(); i++)
	// {
	// 	o << src.getNode_d(i) << " ";
	// }
	return (o);
}

std::deque<Node> PmergeMe::sort_d(const std::deque<Node>& d) const
{
	std::deque<Node> av;
	std::deque<Node> bv;
	std::deque<Node> nbv;
	std::deque<Node> nav;
	std::deque<Node> mav;

	if (d.size() == 1)
	{
		return (d);
	}

	// sort v into av and bv and save in a the corresponding b;
	size_t i = 0;
	while (i < d.size() - 1)
	{
		if (d[i] < d[i + 1])
		{
			av.push_back(d[i + 1]);
			bv.push_back(d[i]);
		}
		else
		{
			av.push_back(d[i]);
			bv.push_back(d[i + 1]);
		}
		av.back().index_where_to_find_underlying_b = av.size() - 1;
		i = i + 2;
	}
	if (d.size() % 2 != 0)
	{
		bv.push_back(d[i]);
	}

	// get a sorted a back;
	nav = sort_d(av);

	// mirror to not lose b data
	mav.resize(av.size());
	for (size_t i = 0; i < nav.size(); i++)
	{
		int x = 0;
		for (size_t j = 0; j < av.size(); j++)
		{
			if (nav[i].unique_index == av[j].unique_index)
			{
				x = j;
				break;
			}
		}
		mav[i] = av[x];
	}

	// sort b by ordering with the information and the acutal index of a in v;
	nbv.resize(bv.size());
	for (size_t i = 0; i < mav.size(); i++)
	{
		nbv[i] = bv[mav[i].index_where_to_find_underlying_b];
	}
	if (bv.size() > mav.size())
	{
		nbv[bv.size() - 1] = bv[bv.size() - 1];
	}

	// create main chain by adding smallest b
	// insert b following binary search with jakobsthal priority list into main chain;
	mav.insert(mav.begin(), nbv[0]);
	int k = 2;
	int jakob = jakobstahl(k);
	for (size_t i = 1; i < nbv.size(); i++)
	{
		while (jakob > static_cast<int>(nbv.size()))
			jakob--;
		mav.insert(mav.begin() + binarySearch_d(0, i + jakob - 2, nbv[jakob - 1], mav), nbv[jakob - 1]);
		--jakob;
		if (jakob == jakobstahl(k - 1))
		{
			jakob = jakobstahl(++k);
			if (jakob > static_cast<int>(nbv.size()))
				jakob = static_cast<int>(nbv.size());
		}
	}
	return mav;
}

const Node& PmergeMe::getNode_d(int i) const
{
	return (_d[i]);
}

int PmergeMe::getSize_d() const
{
	return (_d.size());
}

int PmergeMe::binarySearch_d(int low, int high, Node& item, std::deque<Node>& d) const
{
	if (low > high)
		return low;
	int mid = (low + high) / 2;
	if (d[mid] < item)
	{
		return (binarySearch_d(mid + 1, high, item, d));
	}
	else
	{
		return (binarySearch_d(low, mid - 1, item, d));
	}
}

// dummy version for early testing
	// mav.insert(mav.begin(), nbv[0]);
	// for (size_t i = 1; i < nbv.size(); i++)
	// {
	// 	for (size_t j = 0; j < mav.size(); j++)
	// 	{
	// 		if ((nbv[i] < mav[j]))
	// 		{
	// 			mav.insert(mav.begin() + j, nbv[i]);
	// 			break;
	// 		}
	// 		if (j == mav.size() - 1)
	// 		{
	// 			mav.push_back(nbv[i]);
	// 			break;
	// 		}
	// 	}
	// }

	// dummy version that uses binary search but not Jakosthal;
	// mav.insert(mav.begin(), nbv[0]);
	// for (size_t i = 1; i < nbv.size(); i++)
	// {
	// 	mav.insert(mav.begin() + binarySearch(0, mav.size() - 1, nbv[i], mav), nbv[i]);
	// }

		// std::cout << "av: "; // this for showcasing
	// for (size_t i = 0; i < av.size(); i++)
	// 	std::cout << av[i] << " ";
	// std::cout << std::endl;
	// std::cout << "nav: ";
	// for (size_t i = 0; i < nav.size(); i++)
	// 	std::cout << nav[i] << " ";
	// std::cout << std::endl;
	// std::cout << "mav: ";
	// for (size_t i = 0; i < mav.size(); i++)
	// 	std::cout << mav[i] << " ";
	// std::cout << std::endl;
	// std::cout << "bv: ";
	// for (size_t i = 0; i < bv.size(); i++)
	// 	std::cout << bv[i] << " ";
	// std::cout << std::endl;
	// std::cout << "nbv: ";
	// for (size_t i = 0; i < bv.size(); i++)
	// 	std::cout << nbv[i] << " ";
	// std::cout << std::endl;


		// std::cout << "av: ";
	// for (size_t i = 0; i < av.size(); i++)
	// 	std::cout << av[i].value << " ";
	// std::cout << std::endl;
	// std::cout << "bv: ";
	// for (size_t i = 0; i < bv.size(); i++)
	// 	std::cout << bv[i].value << " ";
	// std::cout << std::endl;
