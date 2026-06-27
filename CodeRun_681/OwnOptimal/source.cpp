#include <iostream>
#include <vector>

/*

27.06.2026
13:41

Task: Tic-tac-toe game. Need to determine if there are five 'X's or 'O's in a row; 
a sequence of five at a 45-degree angle also counts

Idea: For every non-empty cell Matrix[i][j], try to check whether a line of 5 equal symbols starts from this cell.

Pattern: Grid direction checking / Direction vectors

Solution:

Complexity: O(n * m * 4 * 5) = O(n * m)

Brainstorm:

.OXOXO
OXX.O.
XXOOXX
..O..O
OOXX.X

X   X   X
 X  X  X
  X X X  ->
   XXX
XXXXX
    ^
    (0,0) this is start

left        - (-1; 0)
top         - (0; -1);
left/top    - (-1, -1);
right/top   - (1, -1);

*/

class Solution
{
public:
	bool FiveInRow(const std::vector<std::vector<char>>& Matrix)
	{
        int Rows = Matrix.size();
        int Cols = Matrix[0].size();
        
        for (size_t i = 0; i < Rows; i++)
        {
            for (size_t j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == '.') continue;

                if (PlaceFiveRow(Matrix, i, j, -1, 0)) return true;
                if (PlaceFiveRow(Matrix, i, j, 0, -1)) return true; 
                if (PlaceFiveRow(Matrix, i, j, -1, -1)) return true; 
                if (PlaceFiveRow(Matrix, i, j, 1, -1)) return true; 
            }
        }
        return false;        
	}

    bool PlaceFiveRow(const std::vector<std::vector<char>>& Matrix, size_t CurrI, size_t CurrJ, int DirI, int DirJ)
    {
        int Rows = Matrix.size();
        int Cols = Matrix[0].size();

        for (size_t k = 0; k < 5; k++)
        {
            int NewDirI = CurrI + k * DirI;
            int NewDirJ = CurrJ + k * DirJ;
            
            if (NewDirI < 0 || NewDirI >= Rows || NewDirJ < 0 || NewDirJ >= Cols)
            {
                return false;
            }

            if (Matrix[CurrI][CurrJ] != Matrix[NewDirI][NewDirJ]) return false;
        }
        return true;
    }
};


int main() 
{
	int n = 0, m = 0;

    std::cin >> n >> m;
	std::vector<std::vector<char>> Matrix(n, std::vector<char>(m));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cin >> Matrix[i][j];
		}
	}
	Solution Daps;
	std::cout << (Daps.FiveInRow(Matrix) ? "Yes" : "No");
	return 0;
}
