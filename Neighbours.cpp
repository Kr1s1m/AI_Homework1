#include "Neighbours.h"

Neighbours::Neighbours(unsigned int gridDimension)
{
	unsigned int gridBottomLeft = gridDimension * (gridDimension - 1);
	unsigned int gridBottomRight = (gridDimension * gridDimension) - 1;

	gridNeighbours.insert({ 0, {1, gridDimension} });
	gridNeighbours.insert({ gridDimension - 1, {gridDimension - 2, 2 * gridDimension - 1} });
	gridNeighbours.insert({ gridBottomLeft, {gridBottomLeft + 1, gridBottomLeft - gridDimension} });
	gridNeighbours.insert({ gridBottomRight, {gridBottomRight - gridDimension, gridBottomRight - 1} });

	for (unsigned int i = 1; i < gridDimension - 1; i++)
		gridNeighbours.insert({ i, {i - 1, i + gridDimension, i + 1} });

	for (unsigned int i = gridDimension; i < gridBottomLeft; i += gridDimension)
		gridNeighbours.insert({ i, {i - gridDimension, i + 1, i + gridDimension} });

	for (unsigned int i = 2 * gridDimension - 1; i < gridBottomRight; i += gridDimension)
		gridNeighbours.insert({ i, {i - gridDimension, i - 1, i + gridDimension} });

	for (unsigned int i = gridBottomLeft + 1; i < gridBottomRight; i++)
		gridNeighbours.insert({ i, {i - 1, i - gridDimension, i + 1} });

	for(unsigned int i = gridDimension + 1; i < 2 * gridDimension - 1; i++)
		for(unsigned int j = i; j < gridBottomLeft; j += gridDimension)
				gridNeighbours.insert({ j, {j - 1, j - gridDimension, j + 1, j + gridDimension} });

}

std::vector<unsigned int> Neighbours::getAdjacentOf(unsigned int key) const
{
	return gridNeighbours.find(key)->second;
}
