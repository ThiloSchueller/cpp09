#ifndef NODE_HPP
#define NODE_HPP

#include <algorithm>
#include <string>

class Node {
private:

public:
	int value;
	Node* ANode;
	/* Constructors & Destructors */
	Node() = delete;
	Node(char* src);
	// void setANode(Node& ANode);
	// Node& getANode();
	Node(const Node& src); // TODO do i need those?
	Node(Node&& src);
	~Node();

	/* Member Functions */

	/* Basic Operators */
	Node& operator=(const Node& src);
	Node& operator=(Node&& src);
	int operator<(const Node& other);

	/* Getters & Setters */

};

#endif // NODE_HPP