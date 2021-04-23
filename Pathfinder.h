#pragma once

#include "Pathfinding.h"
#include "Heuristic.h"
#include "heuristics.h"
#include "NodeValuePair.h"
#include "Neighbours.h"
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <functional>

class Pathfinder
{
	
		std::stack<State> path;

		Node& startNode;
		const Node& goalNode;
		

		bool goalFound;

		Pathfinding pathfinding;
		Heuristic heuristic;

		unsigned int getOptimalBasedOn(std::function<unsigned int(const State&)>);
	
		unsigned int evaluateNode(const Node&, std::function<unsigned int(const State&)>);

		void getOptimalPath(std::shared_ptr<Node>);
		



	public:

		

		Pathfinder(Node& , const Node&, Pathfinding, Heuristic);

		unsigned int getBestPath();

		void summary() const;

};

