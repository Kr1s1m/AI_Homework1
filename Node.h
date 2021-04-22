#pragma once
#include "State.h"

class Node
{
	private:
		State state;
		std::shared_ptr<Node> parent;
		unsigned int depth;

	public:


		Node(const State&, std::shared_ptr<Node> = nullptr, unsigned int = 0);
		Node(const Node&);
		
		Node& operator=(const Node&);

		bool operator==(const Node&);

		void setParent(std::shared_ptr<Node>);
		void setParent(Node*);

		unsigned int getDepth() const;

		const State& getState() const;
		const std::shared_ptr<Node> getParent() const;


		friend std::ostream& operator<<(std::ostream& os, Node&);

};

