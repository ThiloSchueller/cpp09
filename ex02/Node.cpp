#include "Node.hpp"


Node::Node()
	: value(0), index_where_to_find_underlying_b(0), unique_index(0)
{

}

Node::Node(char* src)
	:value(std::stoi(src)), index_where_to_find_underlying_b(0), unique_index(0)
{
}

int Node::operator<(const Node& other)
{
	return (this->value < other.value);
}

int Node::operator==(const Node& other)
{
	return (this->value == other.value);
}

Node::~Node()
{
}
