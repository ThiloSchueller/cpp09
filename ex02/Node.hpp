#ifndef NODE_HPP
#define NODE_HPP

#include <algorithm>
#include <string>

class Node {
private:

public:
	int value;
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
	int operator<(const Node& other);
	int operator==(const Node& other);
	//int operator<(const Node& other);


	/* Getters & Setters */

};

#endif // NODE_HPP