#pragma once
#include "Node.h"

class NodeValuePair
{
	public:
		Node node;
		unsigned int value;

	

		NodeValuePair(Node&, unsigned int);

		friend bool operator>(const NodeValuePair&, const NodeValuePair&);


};

