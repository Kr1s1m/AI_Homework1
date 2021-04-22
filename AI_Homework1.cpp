
#include "Pathfinder.h"




int main()
{
    //unsigned int startSize = 3;
    //std::vector<unsigned int> startTiles = { 8,7,6,5,4,3,2,1,0 };

    //State start(startSize, startTiles);

   

    State start;
    start.GenerateRandom();


    State goal;



    std::cout << "Start state :\n" << start << std::endl;

    Node startNode(start);
    Node goalNode(goal);

    Pathfinder AC(startNode, goalNode, Pathfinding::AStar, Heuristic::Combined);
    Pathfinder AD(startNode, goalNode, Pathfinding::AStar, Heuristic::Differences);
    Pathfinder AM(startNode, goalNode, Pathfinding::AStar, Heuristic::Manhattan);


    Pathfinder BC(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Combined);
    Pathfinder BD(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Differences);
    Pathfinder BM(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Manhattan);

       
        

    std::cout << "A* + Cmb -----> " << AC.getSolution() << std::endl;
    std::cout << "A* + Dff -----> " << AD.getSolution() << std::endl;
    std::cout << "A* + Man -----> " << AM.getSolution() << std::endl;
    std::cout << std::endl;
    std::cout << "BF + Cmb -----> " << BC.getSolution() << std::endl;
    std::cout << "BF + Dff -----> " << BD.getSolution() << std::endl;
    std::cout << "BF + Man -----> " << BM.getSolution() << std::endl;
    
    //P.summary();
    //Q.summary();

    

   

    return 0;
}


