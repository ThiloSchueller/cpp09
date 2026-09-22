#ifndef NODE_HPP
#define NODE_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <cstdbool>

class Node {
private:
	int _value;
	static int _number_of_comparisons;

public:
	int index_where_to_find_underlying_b;
	int unique_index;

	/* Constructors & Destructors */
	Node();
	Node(char* src);
	Node(const Node& src);
	Node(Node&& src) noexcept;
	~Node();

	/* Member Functions */

	/* Basic Operators */
	bool operator<(const Node& other) const;
	Node& operator=(const Node& src);
	Node& operator=(Node&& src) noexcept;

	/* Getters & Setters */
	int getValue() const;
	static int getNumberOfComparisons();
};

std::ostream& operator<<(std::ostream& o, const Node& src);

#endif // NODE_HPP