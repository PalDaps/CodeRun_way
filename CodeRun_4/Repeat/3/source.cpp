#include <iostream>
#include <vector>

/*

18.11.2025
21:57

Task: Give a chessboard sizes of n*m. We need to understand how many ways we have to move horse figure from (0;0)
to (n-1, m-1)

P.S. | 18.11.2025 | 22:16: - my memory is so bad. I need do something with it

*/


class Solution
{
public:
    int StepHorse(int n, int m)
    {
        std::vector<std::vector<int>> Dp(n, std::vector<int>(m, 0));
        Dp[0][0] = 1;

        for(size_t i = 0; i < n; i++)
        {
            for(size_t j = 0; j < m; j++)
            {
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
    Solution Daps;
    std::cout << Daps.StepHorse(n, m);
    return 0;
}