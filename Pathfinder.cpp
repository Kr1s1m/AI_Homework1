#include "Pathfinder.h"



Pathfinder::Pathfinder( Node& s, const Node& g, Pathfinding p, Heuristic h) : 
    startNode(s), goalNode(g), pathfinding(p), heuristic(h), goalFound(false)
{

}

unsigned int Pathfinder::getSolution()
{
    switch (heuristic)
    {
        case Heuristic::Manhattan :
            return getOptimalBasedOn(manhattanSum);
        break;

        case Heuristic::Differences :
            return getOptimalBasedOn(countDifferences);
        break;

        case Heuristic::Combined:
            return getOptimalBasedOn(combined);
        break;
    }
}

unsigned int Pathfinder::getOptimalBasedOn(std::function<unsigned int(const State&)> h)
{
    std::priority_queue<NodeValuePair, std::vector<NodeValuePair>, std::greater<NodeValuePair>> openList;
    std::set<unsigned int> closedList;

    unsigned int boardSize = goalNode.getState().getBoardSize();

    Neighbours neighbours(boardSize);

    openList.push({ startNode, evaluateNode(startNode, h) });

    while (!openList.empty())
    {
        Node currentNode = openList.top().node;
        State currentState = currentNode.getState();

        if (currentState == goalNode.getState())
        {
            goalFound = true;
            return currentNode.getDepth();
        }

        openList.pop();
        closedList.insert(currentState.toInt());

        for (auto i : neighbours.getAdjacentOf(currentState.getEmptyIndex()))
        {
            State childState(currentState);
            childState.swapEmptyWith(i);

            if (closedList.find(childState.toInt()) != closedList.end())
                continue;


            Node* childNode = new Node(childState, std::shared_ptr<Node>(&currentNode), currentNode.getDepth() + 1);

            openList.push({ *childNode, evaluateNode(*childNode, h) });
            
        }   
        
    }

    return 69696969;
}

unsigned int Pathfinder::evaluateNode(const Node& node, std::function<unsigned int(const State&)> h)
{
    unsigned int evaluation = 0;

    switch (pathfinding)
    {
        case Pathfinding::BestFirst :

            evaluation = h(node.getState());

        break;

        case Pathfinding::AStar:

            evaluation = h(node.getState()) + node.getDepth();

        break;

        default:

            evaluation = 0;

        break;


    }

    return evaluation;
}
