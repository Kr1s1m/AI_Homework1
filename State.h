#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>


class State
{
	private:
		unsigned int boardSize;
		unsigned int emptyIndex;

		std::vector<unsigned int> tiles;


		unsigned int findEmptyIndex() const;
		bool isSolvable() const;

	public:
		State(unsigned int = 3);
		State(unsigned int, std::vector<unsigned int>&);
		State(const State&);


		State& operator=(const State&);
		bool operator==(const State&);


		void GenerateRandom();
		void swapEmptyWith(unsigned int);
		void setTiles(std::vector<unsigned int>&);

		unsigned int getBoardSize() const;
		unsigned int getEmptyIndex() const;
		unsigned int toInt() const;
		
		std::vector<unsigned int> getTiles() const;
		

		friend std::ostream& operator<<(std::ostream&, const State&);


};

