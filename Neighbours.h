#pragma once

#include <map>
#include <vector>

class Neighbours
{
	private:

		std::map<unsigned int, std::vector<unsigned int>> gridNeighbours;

	public:

		Neighbours(unsigned int = 3);

		std::vector<unsigned int> getAdjacentOf(unsigned int) const;

};

