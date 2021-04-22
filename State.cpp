#include "State.h"

State::State(unsigned int bSize)
{
	boardSize = bSize;

	for (unsigned int i = 0; i < bSize*bSize; i++)
		tiles.push_back(i);

	emptyIndex = 0;

}

State::State(unsigned int bSize, std::vector<unsigned int>& arr)
{
	boardSize = bSize;
	tiles = arr;

	emptyIndex = findEmptyIndex();
	
}

State::State(const State& other) : boardSize(other.boardSize), tiles(other.tiles), emptyIndex(other.emptyIndex)
{

}

State& State::operator=(const State& other)
{
	if (this != &other)
	{
		boardSize = other.boardSize;
		tiles = other.tiles;
		emptyIndex = other.emptyIndex;
	}

	return *this;
}

bool State::operator==(const State& other)
{
	return (boardSize == other.boardSize && emptyIndex == other.emptyIndex && tiles == other.tiles);
}

bool State::isSolvable() const
{
	int inversionCount = 0;

	for (unsigned int i = 0; i < tiles.size() - 1; i++)
		for (unsigned int j = i + 1; j < tiles.size(); j++)
			if (tiles[j] && tiles[i] && (tiles[i] > tiles[j]))
				inversionCount++;

	return (inversionCount % 2 == 0);
}

void State::GenerateRandom()
{
	srand(time(NULL));

	do 
	{
		std::random_shuffle(tiles.begin(), tiles.end());

	} while (!isSolvable());

	emptyIndex = findEmptyIndex();
		
}



unsigned int State::findEmptyIndex() const
{
	for (unsigned int i = 0; i < tiles.size(); i++)
		if (tiles[i] == 0)
			return i;

	return tiles.size() + 1;
}

unsigned int State::getBoardSize() const
{
	return boardSize;
}

unsigned int State::getEmptyIndex() const
{
	return emptyIndex;
}

void State::swapEmptyWith(unsigned int i)
{
	
	unsigned int temp = tiles[i];
	tiles[i] = tiles[emptyIndex];
	tiles[emptyIndex] = temp;

	emptyIndex = i;

}

unsigned int State::toInt() const
{
	unsigned int result = 0;

	for (unsigned int i = 0; i < tiles.size(); i++)
		result = result * 10 + tiles[i];

	return result;
		
}


std::vector<unsigned int> State::getTiles() const
{
	return tiles;
}

void State::setTiles(std::vector<unsigned int>& arr)
{
	tiles = arr;
}

std::ostream& operator<<(std::ostream& os, const State& state)
{
	

	for (unsigned int i = 0; i < state.tiles.size(); i++)
	{
		
		os << state.tiles[i] << " ";
		
		if((i + 1) % state.boardSize == 0)
			os << "\n";
	}
		
	return os;

}
