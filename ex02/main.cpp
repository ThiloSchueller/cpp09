#include "PmergeMe.hpp"

int F(int n) // max number of max comparisons for n numbers
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Missing input" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe obj(argc, argv);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error" << std::endl;
	}
	// std::cout << "Number of allowed comparisons " << F(argc - 1) << "\n"
	// 	<< "Number of   used  comparisons " << Node::getNumberOfComparisons() / 2 << "\n" << std::endl;
	return 0;
}