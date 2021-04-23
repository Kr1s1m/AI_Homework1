#pragma once

#include "Pathfinding.h"
#include "Heuristic.h"
#include "heuristics.h"
#include "NodeValuePair.h"
#include "Neighbours.h"
#include <queue>
#include <stack>
#include <set>
#include <functional>

class Pathfinder
{
	
		std::stack<Node> path;

		Node& startNode;
		const Node& goalNode;
		

		bool goalFound;

		Pathfinding pathfinding;
		Heuristic heuristic;


		unsigned int getOptimalBasedOn(std::function<unsigned int(const State&)>);
	
		unsigned int evaluateNode(const Node&, std::function<unsigned int(const State&)>);
		



	public:

		

		Pathfinder(Node& , const Node&, Pathfinding, Heuristic);

		unsigned int getSolution();

		void summary();

};

