#include "NodeValuePair.h"

NodeValuePair::NodeValuePair(Node& _node, unsigned int _value) : node(_node), value(_value)
{
	
}



bool operator>(const NodeValuePair& left, const NodeValuePair& right)
{
	return (left.value > right.value);
}
