#include "PmergeMe.hpp"

/* Constructors & Destructors */

PmergeMe::PmergeMe(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		_v.push_back(Node(argv[i]));
		_v[i - 1].unique_index = i;
	}
	//_v[0]._number_of_comparisons = 0;
	// for (int i = 1; i < argc; i++)
	// {
	// 	_v.push_back(Node(argv[i]));
	// 	_v.back().unique_index = i;
	// }
	std::cout << "read the following numbers: \n" << *this << std::endl;
	_v = sort_v(_v);
	std::cout << "sorted :\n" << *this << std::endl;
}

std::vector<Node> PmergeMe::sort_v(std::vector<Node> v)
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
	// sort v into av and bv 	// save in a the corresponding b;
	size_t i = 0;
	// for (; i < v.size() - 1; i = i + 2)
	while (i < v.size() - 1)
	{
		if (v[i] < v[i + 1])
		{
			av.push_back(v[i + 1]);
			bv.push_back(v[i]);
			//av[i].index_where_to_find_underlying_b = i;
		}
		else
		{
			av.push_back(v[i]);
			bv.push_back(v[i + 1]);
			//av[i].index_where_to_find_underlying_b = i;
		}
		av.back().index_where_to_find_underlying_b = av.size() - 1;
		// if (i == v.size() - 3)
		// {
		// 	bv.push_back(v[i + 2]);
		// }
		i = i + 2;
	}
	if (v.size() % 2 != 0)
	{
		bv.push_back(v[i]);
	}
	// std::cout << "av: ";
	// for (size_t i = 0; i < av.size(); i++)
	// 	std::cout << av[i].value << " ";
	// std::cout << std::endl;
	// std::cout << "bv: ";
	// for (size_t i = 0; i < bv.size(); i++)
	// 	std::cout << bv[i].value << " ";
	// std::cout << std::endl;


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
				//std::cout << "first b " << nav[i].index_where_to_find_underlying_b << " second b " << av[j].index_where_to_find_underlying_b << std::endl;
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

	std::cout << "av: ";
	for (size_t i = 0; i < av.size(); i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
	std::cout << "nav: ";
	for (size_t i = 0; i < nav.size(); i++)
		std::cout << nav[i] << " ";
	std::cout << std::endl;
	std::cout << "mav: ";
	for (size_t i = 0; i < mav.size(); i++)
		std::cout << mav[i] << " ";
	std::cout << std::endl;
	std::cout << "bv: ";
	for (size_t i = 0; i < bv.size(); i++)
		std::cout << bv[i] << " ";
	std::cout << std::endl;
	std::cout << "nbv: ";
	for (size_t i = 0; i < bv.size(); i++)
		std::cout << nbv[i] << " ";
	std::cout << std::endl;

	// insert b following jakobsthalzahl into a;
	// create main chain by adding smallest b

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
	// real version
	mav.insert(mav.begin(), nbv[0]);
	int k = 2;
	int jakob = jakobstahl(k);
	// std::cout << "this :" << jakob << std::endl;
	for (size_t i = 1; i < nbv.size(); i++)
	{
		// std::cout << "jakob :" << jakob << std::endl;
		// std::cout << " upper bound :" << i + jakob - 2 << std::endl;
		while (jakob > static_cast<int>(nbv.size()))
			jakob--;
		// std::cout << "jokob - 1" << jakob - 1 << std::endl;
		// std::cout << "nbv.size()" << nbv.size() << std::endl;
		// std::cout << " nbv[] " << nbv[jakob - 1] << std::endl;
		mav.insert(mav.begin() + binarySearch(0, i + jakob - 2, nbv[jakob - 1], mav), nbv[jakob - 1]);
		--jakob;
		if (jakob == jakobstahl(k - 1))
		{
			jakob = jakobstahl(++k);
			if (jakob > static_cast<int>(nbv.size()))
				jakob = static_cast<int>(nbv.size());
		}
	}
	std::cout << "yepyep\n" << std::endl;
	return mav;
}

int PmergeMe::binarySearch(int low, int high, Node& item, std::vector<Node>& v) const
{
	if (low > high)
		return low; // TODO: can this pass an idex that is out of bounds for the vector
	int mid = (low + high) / 2;
	if (v[mid] < item)
	{
		return (binarySearch(mid + 1, high, item, v));
	}
	else
	{
		return (binarySearch(low, mid - 1, item, v));
	}
}

int PmergeMe::jakobstahl(int k)
{
	// for (int i = 0; i < k; i++)
	// 	std::cout << ((pow(2, i + 1) + pow(-1, i)) / 3) << std::endl;
	return ((pow(2, k + 1) + pow(-1, k)) / 3);


	// int arr[] = { 1, 1, 3, 5, 11, 21, 43, 85 };
	// return arr[k];
}

PmergeMe::~PmergeMe()
{
}

// int PmergeMe::getNumberOfComparison() const
// {
// 	return (_n);
// }

// int PmergeMe::getNodeValue(int i) const
// {
// 	return(_v[i].value);
// }

const Node& PmergeMe::getNode(int i) const
{
	return (_v[i]);
}

int PmergeMe::getSize() const
{
	return(_v.size());
}

std::ostream& operator<<(std::ostream& o, const PmergeMe& src)
{
	for (int i = 0; i < src.getSize(); i++)
	{
		// o << src.getNodeValue(i) << " ";
		o << src.getNode(i) << " ";
	}
	o << std::endl;
	return (o);
}
