#include <iostream>
#include <vector>
#include <climits>

/*

25.06.2026
20:51

Task: You are given an n*m matrix containing the symbols `+` (representing +1), `-` (representing -1), and `?` 
(which can be replaced by either). You need to find the maximum difference between a row sum and a column sum after 
replacing all the symbols.

Idea: replace '?' in the chosen row with '+', and replace '?' in the chosen column with '-'. Find tha max diff, this is 
impossible for the same cell, because one '?' cannot be both +1 and -1. So for an intersection '?' we must subtract 2.

Pattern: Row-column optimization / Try all row-column pairs.

Solution: 

Create arrays:
    SumInRows[n]
    SumInCols[m]
Iterate over all matrix cells.
    For each cell:
    '+' -> SumInRows[i]++, SumInCols[j]++
    '-' -> SumInRows[i]--, SumInCols[j]--
    '?' -> SumInRows[i]++, SumInCols[j]--
Try every pair (row i, column j):
    delta = SumInRows[i] - SumInCols[j]
    If Matrix[i][j] == '?':
    delta -= 2
    Answer is the maximum delta.

Brainstorm: 

 012
0+-+
1+?+

SumInRows[1] is 3
SumInCols[1] is -2
Delta without ? is 3-(-2) = 5
Delta with + is (3)-(-2+1+1) = 3+2-1-1

*/

class Solution
{
public:
    int PlusMinusQuestion(std::vector<std::vector<char>>& Matrix)
    {
        int Rows = Matrix.size();
        int Cols = Matrix[0].size();
        std::vector<int> SumInRows(Rows, 0);
        std::vector<int> SumInCols(Cols, 0);

        for (size_t i = 0; i < Rows; i++)
        {
            for (size_t j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == '+')
                {
                    SumInRows[i]++;
                    SumInCols[j]++;
                }
                else if (Matrix[i][j] == '-')
                {
                    SumInRows[i]--;
                    SumInCols[j]--;
                }
                else if (Matrix[i][j] == '?')
                {
                    SumInRows[i]++;
                    SumInCols[j]--;
                }
            }
        }

        int MaxDelta = INT_MIN;

        for(size_t i = 0; i < Rows; i++)
        {
            int TempDelta = 0;

            for(size_t j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == '?')
                {
                    TempDelta = SumInRows[i] - SumInCols[j] -2;
                }
                else
                {
                    TempDelta = SumInRows[i] - SumInCols[j];
                }

                if(TempDelta > MaxDelta) MaxDelta = TempDelta;
            }
        }
        return MaxDelta;
    }
};

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<char>> Matrix(n, std::vector<char>(m));
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            std::cin >> Matrix[i][j];
        }
    }
    Solution Daps;
    std::cout << Daps.PlusMinusQuestion(Matrix);
    return 0;
}