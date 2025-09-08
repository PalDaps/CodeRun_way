#include <iostream>
#include <vector>
#include <stack>

/*

08.09.2025
15:25

Task: Given a sequence of numbers, we need to find the longest subsequence in it

Idea: We store the longest subsequence for each element

Solution: 

Brainstorm:

Initially, the longest subsequence for each element is an array of size 0.
Then we go through the array:

- Number 4: now the subsequence of size 1 is {4}. Remember the previous element as 4.
- Number 8: 8 > 4 (the previous element), so the maximum subsequence of size 2 is {4, 8}. Remember 8.
- Number 2: 2 < 8, so for 2 the maximum subsequence is {2}.
- Number 6: where to add 6? We have subsequences {4, 8} and {2}. Obviously, we add it to the one whose last element is 
less than 6. Result: {2, 6}.
- Number 2: subsequence is {2}.
- Number 10: we get {4, 8, 10} and {2, 6, 10}.
- Number 6: subsequence is {2, 6}.
- Number 29: we get {4, 8, 10, 29}, {2, 6, 10, 29}, {2, 6, 29}.

P.S. Doing this task about one houre and tilted

*/

class SolutionDp
{
	public:
	std::stack LongestIncreasingSubsequence(std::vector<int> Array)
	{
		// Contain for each element from Array his subsequence
		std::vector<std::stack<int>> Dp(Array.size());
		// For first element most subsequence is this element
		Dp[0].push(Array[0]);

		for(int i = 1; i < Array.size(); i++)
		{
			int CurrElement = Array[i];

			// Need check the most element in subsequence for previosly element
			std::stack<int>> PrevStack = Dp[i-1];
			int PrevMax = PrevStack.top();

			if (CurrElement > PrevMax)
			{
				PrevStack.push(CurrElement);
				Dp[i] = PrevStack;
			}
			else
			{
				Dp[i].push(CurrElement);
			}
		}
	}

	void AddToSubsequences(std::vector<std::stack<int>>& Dp, int C)
	{
		int Rows = Dp.size();
		for(int i = 0; i < Rows; i++)
		{
			std::stack<int>> CurrStack = Dp[i];
			if(!CurrStack.empty())
			{
				int Max = CurrStack.top();
				if (CurrElement > Max) 
				{
					CurrStack.push(CurrElement);
				}
			}
		}
	}
}
int main() 
{
	int n = 0;
	std::cin >> n;

	std::vector<int> InputArray(n, 0);
	for(int i = 0; i < n; i++) std::cin >> InputArray[i];


	return 0;
}