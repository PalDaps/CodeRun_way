#include <iostream>
#include <queue>
#include <vector>

/*

18.11.2025
22:18

Task: We have an adjacency matrix(Size of rows == size of cols), and we need to find the minimum distance from 
one point to another point, as specified by the user.

P.S. | 18.11.2025 | 23:02: - I can not to imagine the whole algorithm in my head. I can rotate this thing.
P.S. | 18.11.2025 | 23:59: - I wanna try to become the best of mine copy
*/

class Solution
{
public:
    int BfsAdjancyMatrix(std::vector<std::vector<int>>& AdjMatrix, int Start, int Finish)
    {
        size_t Size = AdjMatrix.size();

        // Convert to array indexes
        Start--;
        Finish--;
        
        // After a see it graph, i want to make array with distace from start, to each vertex?!
        std::vector<int> Distance(Size, -1);
        Distance[Start] = 0;

        // And need a queue for neighbours of start vertex and next
        std::queue<int> Q;
        Q.push(Start);

        while(!Q.empty())
        {
            int Current = Q.front();
            Q.pop();

            for(size_t Neighbour = 0; Neighbour < Size; Neighbour++)
            {
                if(AdjMatrix[Current][Neighbour] == 1 && Distance[Neighbour] == -1)
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

    std::cout << Daps.BfsAdjancyMatrix(AdjancyMatrix, Start, Finish);
    return 0;
}

