#include "NodeValuePair.h"

NodeValuePair::NodeValuePair(Node& _node, unsigned int _value) : node(_node), value(_value)
{
	
}



bool operator>(const NodeValuePair& left, const NodeValuePair& right)
{
	//if (left.value == right.value)
		//return left.node.getDepth() > right.node.getDepth();

	return (left.value > right.value);
}
