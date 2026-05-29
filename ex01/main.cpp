#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "program requires one argument" << std::endl;
		return 1;
	}
	std::string term = argv[1];
	try {
		RPN rpn(term);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}