#include <iostream>
#include <vector>
#include <climits>

/*

28.06.2026
15:10

Task: You are given an n*m matrix containing the symbols `+` (representing +1), `-` (representing -1), and `?` 
(which can be replaced by either). You need to find the maximum difference between a row sum and a column sum after 
replacing all the symbols.

Idea: replace '?' in the chosen row with '+', and replace '?' in the chosen column with '-'. Find tha max diff, this is 
impossible for the same cell, because one '?' cannot be both +1 and -1. So for an intersection '?' we must subtract 2.

Pattern: Row-column optimization / Try all row-column pairs.

Solution: 

Brainstorm: 

P.S. | 28.06.2026 | 15:43: Success repeat. I need the right strategy for reviewing tasks.
*/

class Solution
{
public:
    int PlusMinusQuestion(const std::vector<std::vector<char>>& Matrix)
    {
        int Rows = Matrix.size();
        int Cols = Matrix[0].size();

        std::vector<int> SumInRows(Rows, 0);
        std::vector<int> SumInCols(Cols, 0);

        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == '?')
                {
                    SumInRows[i]++;
                    SumInCols[j]--;
                }
                else if (Matrix[i][j] == '+')
                {
                    SumInRows[i]++;
                    SumInCols[j]++;
                }
                else if (Matrix[i][j] == '-')
                {
                    SumInRows[i]--;
                    SumInCols[j]--;
                }
            }
        }

        int Result = INT_MIN;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                int TempResult = 0;

                if (Matrix[i][j] == '?')
                {
                    TempResult = SumInRows[i] - SumInCols[j] - 2;
                }
                else
                {
                    TempResult = SumInRows[i] - SumInCols[j]; 
                }

                if (TempResult > Result) Result = TempResult;
            }
        }

        return Result;
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
    std::cout << Daps.PlusMinusQuestion(Matrix);
	return 0;
}
