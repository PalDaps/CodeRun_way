#include <iostream>
#include <queue>
#include <vector>

/*

19.11.2025
11:31

Task: Give a adjancy matrix(size of Rows == size of Cols) and need to calculate minimum distance from one point to
another point.

*/

class Solution
{
public:
    int BfsAdjancyMartix(std::vector<std::vector<int>>& AdjancyMatrix, int Start, int Finish)
    {
        size_t Size = AdjancyMatrix.size();

        Start--;
        Finish--;

        std::vector<int> Distance(Size, -1);
        Distance[Start] = 0;

        std::queue<int> Q;
        Q.push(Start);

        while(!Q.empty())
        {
            int Current = Q.front();
            Q.pop();

            for(size_t Neighbour = 0; Neighbour < Size; Neighbour++)
            {
                if(AdjancyMatrix[Current][Neighbour] == 1 && Distance[Neighbour] == -1)
                {
                    Distance[Neighbour] = Distance[Current] + 1;
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
    std::vector<std::vector<int>> AdjancyMatrix(n, std::vector<int>(n, 0));
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            std::cin >> AdjancyMatrix[i][j];
        }
    }
    int Start = 0, Finish = 0; 
    std::cin >> Start >> Finish;
    Solution Daps;
    std::cout << Daps.BfsAdjancyMartix(AdjancyMatrix, Start, Finish);
    return 0;
}