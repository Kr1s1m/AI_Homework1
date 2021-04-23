#include "heuristics.h"

unsigned int manhattanSum(const State& state)
{
	unsigned int totalSum = 0;

	unsigned int manhattan = 0;

	int currX, currY, goalX, goalY;

	std::vector<unsigned int> tiles = state.getTiles();
	unsigned int currSize = state.getBoardSize();

	for (unsigned int i = 0; i < currSize; i++)
	{
		if (tiles[i] == 0)
			continue;

		currX = i / currSize;
		currY = i % currSize;

		goalX = tiles[i] / currSize;
		goalY = tiles[i] % currSize;


		manhattan = abs(goalX - currX) + abs(goalY - currY);

		totalSum += manhattan;
	}

	return totalSum;
}

unsigned int countDifferences(const State& state)
{
	unsigned int count = 0;

	std::vector<unsigned int> tiles = state.getTiles();

	for (unsigned int i = 0; i < tiles.size(); i++)
	{
		if (tiles[i] == 0)
			continue;

		if (tiles[i] != i)
			count++;
	}

	return count;
}

unsigned int combined(const State& state)
{
	return manhattanSum(state) + countDifferences(state);
}