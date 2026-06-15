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
	// void setANode(Node& ANode);
	// Node& getANode();
	~Node();

	/* Member Functions */

	/* Basic Operators */
	bool operator<(const Node& other) const;
	int operator==(const Node& other);
	//int operator<(const Node& other);


	/* Getters & Setters */
	int getValue() const;
	static int getNumberOfComparisons();
};

std::ostream& operator<<(std::ostream& o, const Node& src); //friend and no getValue would be nicer, but not allowed from subject;

#endif // NODE_HPP