
#include "Pathfinder.h"

int main()
{

    State startState;
    State goalState;
   
    Node goalNode(goalState);

    unsigned int am = 0;
    unsigned int ad = 0;
    unsigned int ac = 0;
    unsigned int ae = 0;
    unsigned int bm = 0;
    unsigned int bd = 0;
    unsigned int bc = 0;
    unsigned int be = 0;

    unsigned int testsCount = 10;
    
    for (unsigned int i = 0; i < testsCount; i++)
    {
        startState.GenerateRandom();
        Node startNode(startState);
        
        Pathfinder AD(startNode, goalNode, Pathfinding::AStar, Heuristic::Differences);
        Pathfinder AM(startNode, goalNode, Pathfinding::AStar, Heuristic::Manhattan);
        Pathfinder AC(startNode, goalNode, Pathfinding::AStar, Heuristic::Combined);
        Pathfinder AE(startNode, goalNode, Pathfinding::AStar, Heuristic::Euqlid);
        
        Pathfinder BD(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Differences);
        Pathfinder BM(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Manhattan);
        Pathfinder BC(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Combined);
        Pathfinder BE(startNode, goalNode, Pathfinding::BestFirst, Heuristic::Euqlid);

        am += AM.getBestPath();
        ad += AD.getBestPath();
        ac += AC.getBestPath();
        ae += AE.getBestPath();

        bm += BM.getBestPath();
        bd += BD.getBestPath();
        bc += BC.getBestPath();
        be += BE.getBestPath();

    }

    std::cout << "Results for an average of " << testsCount << " tests:\n";

    std::cout << "A* + Manhattan -------> " << (double)am / testsCount << std::endl;
    std::cout << "A* + Differences -----> " << (double)ad / testsCount << std::endl;
    std::cout << "A* + Man & Diff ------> " << (double)ac / testsCount << std::endl;
    std::cout << "A* + Euqlid ----------> " << (double)ae / testsCount << std::endl;

    std::cout << "BF + Manhattan -------> " << (double)bm / testsCount << std::endl;
    std::cout << "BF + Differences -----> " << (double)bd / testsCount << std::endl;
    std::cout << "BF + Man & Diff ------> " << (double)bc / testsCount << std::endl;
    std::cout << "BF + Euqlid ----------> " << (double)be / testsCount << std::endl;
   

    return 0;
}


