
#include "Pathfinder.h"




int main()
{
    //unsigned int startSize = 3;
    //std::vector<unsigned int> startTiles = { 6,3,4,8,0,2,1,5,7 };

    //State start(startSize, startTiles);

   

    State start;
    start.GenerateRandom();


    State goal;



    std::cout << "Start state :\n" << start << std::endl;

    Node startNode(start);
    Node goalNode(goal);

    //Pathfinder AC(startNode, goalNode, Pathfinding::AStar, Heuristic::Combined);
    Pathfinder AD(startNode, goalNode, Pathfinding::AStar, Heuristic::Differences);
    Pathfinder AM(startNode, goalNode, Pathfinding::AStar, Heuristic::Manhattan);
    Pathfinder AE(startNode, goalNode, Pathfinding::AStar, Heuristic::Euqlid);


    //Pathfinder BC(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Combined);
    Pathfinder BD(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Differences);
    Pathfinder BM(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Manhattan);
    Pathfinder BE(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Euqlid);

    std::cout << AM.getBestPath() << std::endl;
    std::cout << AD.getBestPath() << std::endl;
    std::cout << AE.getBestPath() << std::endl;

    std::cout << BM.getBestPath() << std::endl;
    std::cout << BD.getBestPath() << std::endl;
    std::cout << BE.getBestPath() << std::endl;
   

    return 0;
}


