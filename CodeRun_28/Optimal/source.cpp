#include <iostream>
#include <vector>
#include <stack>

/*

08.09.2025
17:44

Task: Given a sequence of numbers, we need to find the longest subsequence in it

Idea: We store the longest subsequence for each element. When we consider a new element, we check which of the previous 
subsequences it can extend (i.e., which have a last element smaller than the current one). We update the information for 
each applicable subsequence.

Solution: 

Brainstorm:

*/

class SolutionDp
{
public:
	std::vector<int> LongestIncreasingSubsequence(std::vector<int> Array)
	{
        int Size = Array.size();
        // Dp array contain LIS for each element from array
        std::vector<std::vector<int>> Dp(Size);

        for(int i = 0; i < Size; i++)
        {
            // Firstly add to current element
            Dp[i].push_back(Array[i]);

            // Need to check previosly LIS'es
            for(int j = 0; j < i; j++)
            {
                // Check the most element in previosly LIS'es and check sizes of LIS'es
                // We need take to largest subsequenses with current element - Array[i]
                if (Array[i] > Array[j] && Dp[j].size()+1 > Dp[i].size())
                {
                    // New LIS for Dp[i]
                    Dp[i] = Dp[j];
                    // Add curr element
                    Dp[i].push_back((Array[i]));
                }
            }
        }

        std::vector<int> Lis;
        for(int i = 0; i < Size; i++)
        {
            if (Dp[i].size() > Lis.size()) Lis = Dp[i];
        }

        return Lis;
	}

};

int main() 
{
	int n = 0;
	std::cin >> n;

	std::vector<int> InputArray(n, 0);
	for(int i = 0; i < n; i++) std::cin >> InputArray[i];

    SolutionDp Daps;
    std::vector<int> Result = Daps.LongestIncreasingSubsequence(InputArray);
    for(int i = 0; i < Result.size(); i++)
    {
        std::cout << Result[i] << " ";
    }
	return 0;
}