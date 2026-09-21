#include "Node.hpp"

int Node::_number_of_comparisons = 0;

Node::Node()
	: _value(0), index_where_to_find_underlying_b(0), unique_index(0)
{
}

Node::Node(char* src)
	: _value(std::stoi(src)), index_where_to_find_underlying_b(0), unique_index(0)
{
}

Node::Node(const Node& src)
{
	*this = src;
}

Node::~Node()
{
}

Node& Node::operator=(const Node& src)
{
	if (this != &src)
	{
		this->_value = src._value;
		this->index_where_to_find_underlying_b = src.index_where_to_find_underlying_b;
		this->unique_index = src.unique_index;
	}
	return *this;
}

bool Node::operator<(const Node& other) const
{
	this->_number_of_comparisons++;
	return (this->_value < other._value);
}

int Node::getValue() const
{
	return (this->_value);
}

int Node::getNumberOfComparisons()
{
	return (_number_of_comparisons);
}


std::ostream& operator<<(std::ostream& o, const Node& src)
{
	o << src.getValue();
	return o;
}