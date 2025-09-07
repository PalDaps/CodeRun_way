#include <iostream>
#include <vector>

/*

07.09.2025
19:48

Task: A chessboard of size N*M is given, and a knight that can move in two ways: 1. one down and two to the right; 2. two down and one to the right. 
We need to determine how many ways there are for this knight to reach the rightmost cell of the board.

Idea: Iterative fill Dp-Table, where each cell indicates how many ways you can get to it from the cell (0;0)

Solution: 

Brainstorm:

P.S. | 07.08.2025 | 21:51: Very beatifull. The time complexity will be o(n*m).

*/

class SolutionDp
{
public:

	void StepHorse(int n, int m)
	{
        // Table Dp, where each cell indicates how many ways you can get to it from the cell (0;0)
        std::vector<std::vector<int>> Dp(n, std::vector<int>(m, 0));

        // Intial state, we can only get to the point (0;0) in one way
        Dp[0][0] = 1;

        // Fill all Dp table
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // If we step using the first method, we look at how many ways we reached the previous cell and add that to the current cell.
                if (i >= 1 && j >= 2) Dp[i][j] += Dp[i-1][j-2];
                // The same for another cell
                if (i >= 2 && j >= 1) Dp[i][j] += Dp[i-2][j-1];
            }
        }

        std::cout << Dp[n-1][m-1];
	}
};

int main() 
{
    int n = 0, m = 0;
	std::cin >> n >> m;
	SolutionDp Daps;
	Daps.StepHorse(n, m);
	return 0;
}