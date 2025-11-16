#include <iostream>

/*

06.10.2025
14:34

Task: Two numbers n and k are given. n is the initial number, k is the number of seconds. You need to determine what number will be calculated after k seconds 
according to the following algorithm: at each iteration, the last digit of the resulting number from the previous iteration is added to the resulting number

Idea: %10

Solution:

Brainstorm:

*/

class Solution
{
public:
	int IncrementScoreboard(int n, int k)
	{
        int Result = n;
        for(size_t i = 0; i < k; i++)
        {
            int LastDigit = Result%10;
            Result += LastDigit;
            std::cout << Result << std::endl;
        }

        return Result;
    }
};

int main() 
{
    int n = 0, k = 0;
    std::cin >> n >> k;

    Solution Daps;
    std::cout << Daps.IncrementScoreboard(n, k);
	return 0;
}
