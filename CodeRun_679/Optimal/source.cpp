#include <iostream>

/*

24.06.2026
21:31

Task: Two numbers n and k are given. n is the initial number, k is the number of seconds. You need to determine what number will be calculated after k seconds 
according to the following algorithm: at each iteration, the last digit of the resulting number from the previous iteration is added to the resulting number

Idea: find a pattern in adding the last digit to a number. 2 -> 4 -> 8 -> 6 it's cycle in each 

Pattern: Cycle detection / Last digit cycle / Batch simulation

Solution: 

Why odd n is processed separately:
If n is odd, after one operation it either:

enters the cycle 2 -> 4 -> 8 -> 6
or becomes a number ending with 0 and stops changing

k / 4 means: how many full cycles of 4 operations are inside k
k % 4 means: how many operations are left after full cycles

Brainstorm: 

0: 0
1: 1 2 4 8 16 22 24 28 36 42 44 -> next will be cycle 
2: 2 4 8 16 22 24 -> cycle
3: 3 6 12 14 -> cycle
4: 4 8 12 -> cycle
5: 5 10 15 20 -> 5 or 0
6: 6 12 -> cycle
7: 7 14 -> cycle
8: 8 -> cycle
9: 9 18 26 -> cycle

0 -> 0
1 -> 2
2 -> 4
3 -> 6
4 -> 8
5 -> 0
6 -> 2
8 -> 6
9 -> 8

2 -> 4 -> 8 -> 6
n%2 == 0 has cycle
n%2 != 0 need to +1 for cycle

*/

class Solution
{
public:
	long long int IncrementScoreboard(long long int n, long long int k)
	{

        if (n%2 != 0 && k > 0)
        {
            n += n%10;
            k -= 1;  
        }
        
        if (n%10 == 0) return n;
        else
        {
            long long int Cycles = k / 4;
            n += (2 + 4 + 6 + 8)*Cycles;
            k %= 4;
            for(int i = 0; i < k; i++)
            {
                n += n%10;
            }
        }

        return n;
    }
};

int main() 
{
    long long int n = 0, k = 0;
    std::cin >> n >> k;

    Solution Daps;
    std::cout << Daps.IncrementScoreboard(n, k);
	return 0;
}