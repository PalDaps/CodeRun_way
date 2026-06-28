#include <iostream>

/*

28.06.2026
15:03

Task: Two numbers n and k are given. n is the initial number, k is the number of seconds. You need to determine what number will be calculated after k seconds 
according to the following algorithm: at each iteration, the last digit of the resulting number from the previous iteration is added to the resulting number

Idea: find a pattern in adding the last digit to a number. 2 -> 4 -> 8 -> 6 it's cycle in each 

Pattern: Cycle detection / Last digit cycle / Batch simulation

Solution: 

Brainstorm: 

P.S. | 28.06.2026 | 15:03: Success repeat. I need the right strategy for reviewing tasks.

*/

class Solution
{
    public:
    long long int IncrementTable(long long int n, long long int k)
    {
        if (n%2 != 0 && k > 0)
        {
            n += n%10;
            k--;
        }

        if (n%10 == 0) return n;
        else
        {
            long long int Cycles = k / 4;
            n += (2+4+6+8)*Cycles;

            k %= 4;
            for (int i = 0; i < k; i++)
                n += n%10;
        }
        return n;
    }
};

int main() 
{
    long long int n = 0, k = 0;
    std::cin >> n >> k;
    Solution Daps;
    std::cout << Daps.IncrementTable(n, k);
	return 0;
}
