#include "Neighbours.h"

Neighbours::Neighbours(unsigned int gridDimension)
{
	if (gridDimension == 3)
	{
		gridNeighbours.insert({ 0, {1, 3} });
		gridNeighbours.insert({ 1, {0, 2, 4} });
		gridNeighbours.insert({ 2, {1, 5} });
		gridNeighbours.insert({ 3, {0, 4, 6} });
		gridNeighbours.insert({ 4, {1, 3, 5, 7} });
		gridNeighbours.insert({ 5, {2, 4, 8} });
		gridNeighbours.insert({ 6, {3, 7} });
		gridNeighbours.insert({ 7, {4, 6, 8} });
		gridNeighbours.insert({ 8, {5, 7} });
	}
	else
	{
		unsigned int gridBottomLeft = gridDimension * (gridDimension - 1);
		unsigned int gridBottomRight = (gridDimension * gridDimension) - 1;

		gridNeighbours.insert({ 0, {1, gridDimension} });
		gridNeighbours.insert({ gridDimension - 1, {gridDimension - 2, 2 * gridDimension - 1} });
		gridNeighbours.insert({ gridBottomLeft, {gridBottomLeft + 1, gridBottomLeft - gridDimension} });
		gridNeighbours.insert({ gridBottomRight, {gridBottomRight - gridDimension, gridBottomRight - 1} });

		for (unsigned int i = 1; i < gridDimension - 1; i++)
			gridNeighbours.insert({ i, {i - 1, i + 1, i + gridDimension} });

		for (unsigned int i = gridDimension; i < gridBottomLeft; i += gridDimension)
			gridNeighbours.insert({ i, {i - gridDimension, i + 1, i + gridDimension} });

		for (unsigned int i = 2 * gridDimension - 1; i < gridBottomRight; i += gridDimension)
			gridNeighbours.insert({ i, {i - gridDimension, i - 1, i + gridDimension} });

		for (unsigned int i = gridBottomLeft + 1; i < gridBottomRight; i++)
			gridNeighbours.insert({ i, {i - gridDimension, i - 1, i + 1} });

		for (unsigned int i = gridDimension + 1; i < 2 * gridDimension - 1; i++)
			for (unsigned int j = i; j < gridBottomLeft; j += gridDimension)
				gridNeighbours.insert({ j, {j - gridDimension, j - 1, j + 1, j + gridDimension} });
	}

}

std::vector<unsigned int> Neighbours::getAdjacentOf(unsigned int key) const
{
	return gridNeighbours.find(key)->second;
}
