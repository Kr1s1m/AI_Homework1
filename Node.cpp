#include "Node.h"

Node::Node(const State& s, std::shared_ptr<Node> p, unsigned int d) :  state(s), depth(d)
{
    parent = p;
}

Node::Node(const Node& other) : state(other.state), parent(other.parent), depth(other.depth)
{
    
}

Node& Node::operator=(const Node& other)
{
    if (this != &other)
    {
        state = other.state;
        parent = other.parent;
        depth = other.depth;
    }

    return *this;
}

bool Node::operator==(const Node& other)
{
    return (state == other.state);
}

void Node::setParent(std::shared_ptr<Node> p)
{
    parent = p;
}

void Node::setParent(Node* p)
{
    parent.reset(p);
}

unsigned int Node::getDepth() const
{
    return depth;
}

const State& Node::getState() const
{
    return state;
}

const std::shared_ptr<Node> Node::getParent() const
{
    return parent;
}

std::ostream& operator<<(std::ostream& os, Node& node)
{
    os << node.state;

    return os;
}
