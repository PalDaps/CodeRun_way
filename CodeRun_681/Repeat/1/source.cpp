#include <iostream>
#include <vector>

/*

28.06.2026
16:31

Task: Tic-tac-toe game. Need to determine if there are five 'X's or 'O's in a row; 
a sequence of five at a 45-degree angle also counts

Idea: For every non-empty cell Matrix[i][j], try to check whether a line of 5 equal symbols starts from this cell.

Pattern: Grid direction checking / Direction vectors

Solution:

Complexity: O(n * m * 4 * 5) = O(n * m)

Brainstorm:

*/

class Solution
{
public:
    bool FiveInRow(std::vector<std::vector<char>>& Matrix)
    {
        int Rows = Matrix.size();
        int Cols = Matrix[0].size();

        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == '.') continue;

                if (CheckDirection(Matrix, i, j, -1, 0)) return true;
                if (CheckDirection(Matrix, i, j, -1, -1)) return true;    
                if (CheckDirection(Matrix, i, j, 0, -1)) return true;    
                if (CheckDirection(Matrix, i, j, 1, -1)) return true;                    
            }
        }

        return false;
    }

    bool CheckDirection(std::vector<std::vector<char>>& Matrix, int i, int j, int DirI, int DirJ)
    {
        int Rows = Matrix.size();
        int Cols = Matrix[0].size();

        for (int k = 0; k < 5; k++)
        {
            int CheckDirI = i + DirI*k;
            int CheckDirJ = j + DirJ*k;
            
            if (CheckDirI < 0 || CheckDirI >= Rows || CheckDirJ < 0 || CheckDirJ >= Cols) return false;

            if (Matrix[i][j] != Matrix[CheckDirI][CheckDirJ]) return false;
        }

        return true;
    }
};

int main() 
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<char>> Matrix(n, std::vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> Matrix[i][j];
        }
    }

    Solution Daps;
    std::cout << (Daps.FiveInRow(Matrix) ? "Yes" : "No");
	return 0;
}
