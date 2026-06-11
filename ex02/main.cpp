#include "PmergeMe.hpp"

// void insertionSort(std::vector<int>& a)
// {
// 	for (std::size_t i = 1; i < a.size(); ++i) {
// 		int key = a[i];
// 		std::size_t j = i;

// 		while (j > 0 && a[j - 1] > key) {
// 			a[j] = a[j - 1];
// 			--j;
// 		}
// 		a[j] = key;
// 	}
// }

int F(int n) // max number of max comparisons for n numbers
{
	int sum = 0;
	for (int k = 1; k <= n; ++k) {
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return sum;
}


// int main()
// {
// 	std::vector<int> a = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };

// 	insertionSort(a);

// 	std::cout << "Sorted array: \n";
// 	for (int i = 0; i < (int)a.size(); i++)
// 		std::cout << " " << a[i];

// 	return 0;
// }

int main(int argc, char** argv)
{
	if (argc == 1)
		return 1;
	PmergeMe obj(argc, argv);
	std::cout << obj << std::endl;
	std::cout << "Number of allowed comparisons " << F(argc - 1) << "\n"
		<< "Number of   used  comparisons " << obj.getNumberOfComparison() << "\n" << std::endl;
	return 0;
}