#include "iostream"
#include "vector"

/*

25.09.2025
15:54

Task: Given a chessboard with size of n*m and one figure is a horse. Horse can step in two ways: one bottom and
two right or two right and one bottom. We need to understand how much ways we can place horse from frist cell to
last cell(Bottom-Right corner)

*/

class RepeatRecursive
{
public:

    int Solve(int n, int m)
    {
        int Result = 0;
        BruteForce(0, 0, n, m, Result);
        return Result;
    }

    void BruteForce(int i, int j, int n, int m, int& Result)
    {
        if (i == n - 1 && j == m - 1)
        {
            Result++;
            return;
        }
        
        std::vector<std::vector<int>> Ways = {{1,2}, {2, 1}};

        for(auto& Way : Ways)
        {
            int NewI = i + Way[0];
            int NewJ = j + Way[1];
            if (NewI < n && NewJ < m) BruteForce(NewI, NewJ, n, m, Result);
        }
    }

};

int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    RepeatRecursive Daps;
    std::cout << Daps.Solve(n, m);
    return 0;
}