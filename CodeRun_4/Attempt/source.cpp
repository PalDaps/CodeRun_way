#include <iostream>

/*

06.09.2025
10:51

Task: A chessboard of size N*M is given, and a knight that can move in two ways: 1. one down and two to the right; 2. two down and one to the right. 
We need to determine how many ways there are for this knight to reach the rightmost cell of the board.

Idea: Full recursive search

Solution: Recursive solution with all options. If we reach the end, then +1 to Result. After that, we try to step through the second option.

Brainstorm:

How to evaluate the time of the algorithm? 
There is a board n*m. You need to get from point (0;0) to point (n-1, m-1). 
Since the piece is a knight, it moves +1, +2 or +2, +1, which is a total of 3. 
In the end, we will have the speed: (n-1)+(m-1)/2 = (n+m-2)/3. 
Since there are two options for each move, the total complexity will be o(2^((n+m-2)/3)).

It is obvious that y=2^x/3 is worse than y=x when x > 10.

*/

class SolutionRecursive
{
public:

	void StepHorse(int n, int m)
	{	
		int CurrRow = 0, CurrCol = 0, Result = 0;
		Recursive(CurrRow, CurrCol, n, m, Result);
		std::cout << Result;
	}

	void Recursive(int CurrRow, int CurrCol, int n, int m, int& Result)
	{
		// If we go to end, need to increment Result and step to another option
		if (CurrRow == n - 1 && CurrCol == m - 1)
		{
			Result++;
			return;
		}

		// Possible steps
		int Steps[2][2] = {{2, 1},{1, 2}};

        // Full search
		for(auto& Step : Steps)
		{
			int NewRow = CurrRow + Step[0];
			int NewCol = CurrCol + Step[1];
            if (NewRow < n && NewCol < m)
			    Recursive(NewRow, NewCol, n, m, Result);
		}
	}
};

int main() 
{
    int n = 0, m = 0;
	std::cin >> n >> m;
	SolutionRecursive Daps;
	Daps.StepHorse(n, m);
	return 0;
}