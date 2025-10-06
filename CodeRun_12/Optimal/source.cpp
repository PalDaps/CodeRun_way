#include <iostream>
#include <vector>
#include <queue>

/*

08.09.2025
14:19

Task: We have an adjacency matrix, and we need to find the minimum distance from one point to another point, as specified 
by the user.

Idea: First, we check the closest neighbours and update their distances. Then, we continue checking their neighbours 
until we reach the minimum distance.

Solution: 

1. We use an array to store the distance to each vertex.
2. We use a queue to process the neighbours in order.

The main algorithm works as follows:

1. Remove the first element from the queue.
2. Look at all of its neighbours. If a neighbour has not yet been assigned a distance from the starting point, update it.
3. Add that neighbour to the queue so that its own neighbours can be explored later.

P.S. The only thing I don’t understand is why here in if (AdjMatrix[Point][Neighbour]) we check the neighbours with respect 
to the row. What would change if we checked the neighbours with respect to the column?

Brainstorm:

*/

class Solution
{
public:

	int BfsAdjacencyMartix(std::vector<std::vector<int>> AdjMatrix, int Start, int Finish)
	{
		int Size = AdjMatrix.size();
		// Firstly, convert into indices for iteration
		Start--;
		Finish--;
		
		// Need array to store the distance to each vertex
		// The distance to start point is 
		std::vector<int> Distance(Size, -1);
		Distance[Start] = 0;

		// Need queue to process the neighbours in order
		// Firstly point is Start point
		std::queue<int> Q;
		Q.push(Start);

		// Process all neighbours of first vertex in queue, while queue is not empty
		while(!Q.empty())
		{
			// Take first
			int Point = Q.front();
			// Delete this vertex from queue
			Q.pop();

			// Need check all neighbours of this Point
			for(int Neighbour = 0; Neighbour < Size; Neighbour++)
			{
				// If Point connect with Neighbour and we still dont know distance to this Neighbour
				if (AdjMatrix[Point][Neighbour] == 1 && Distance[Neighbour] == -1)
				{
					// Process distance to neighbour
					Distance[Neighbour] = Distance[Point] + 1;
					// And push it, because later we need to check his neighbours
					Q.push(Neighbour);
				}
			}
		}

		return Distance[Finish];
	}
};

int main() 
{
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<int>> AdjMatrix(n, std::vector<int>(n, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			std::cin >> AdjMatrix[i][j];
		}
	}

	int Start = 0, Finish = 0;
	std::cin >> Start >> Finish;

	Solution Daps;
	std::cout << Daps.BfsAdjacencyMartix(AdjMatrix, Start, Finish);
	

	return 0;
}