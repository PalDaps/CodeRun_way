#include <iostream>
#include <vector>

/*

16.11.2025
16:45

Task: Given a chessboard of n*m size. We need to understand, there are how many ways a place horse figure
from (0; 0) point to (n-1, m-1) point. Horse-figure can step in two ways, first way is two right and one bottom, 
and the second way is one bottom and two right. 

P.S. | 16.11.2025 | 17:21: - need to buff my memmory. It's awfull.

*/


class SolutionDp
{
public:
    int HorseStep(int n, int m)
    {
        std::vector<std::vector<int>> Dp(n, std::vector<int>(m, 0));
        
        Dp[0][0] = 1;

        for(size_t i = 0; i < n; i++)
        {

            for(size_t j = 0; j < m; j++)
            {
                // Omg
                if(i >= 1 && j >= 2) Dp[i][j] += Dp[i-1][j-2];
                if(i >= 2 && j >= 1) Dp[i][j] += Dp[i-2][j-1];
            }
        }
        return Dp[n-1][m-1];
    }
};

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    SolutionDp Daps;
    std::cout << Daps.HorseStep(n, m);
    return 0;
}