#include "Node.hpp"


Node::Node(char* src)
	:value(std::stoi(src)), ANode(NULL)
{
}

int Node::operator<(const Node& other)
{
	return (this->value < other.value);
}