#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <vector>

/*
28.05.2026
15:34

Task: The first line specifies two numbers: n—the number of problems created by people and k—the number of problems required in the contest. The second line 
lists n numbers, where each number determines the topic to which the i-th problem belongs (numbering starts with 1).

Idea: Sort the verctor, and then need to shift all uniques value to start of vector

Solution:

Brainstorm:
*/


class Solution
{
public:

    std::vector<int> Topics(int n, int k, std::vector<int> Topics)
    {
        std::sort(Topics.begin(), Topics.end());
        for(size_t Slow = 0, Fast = 0; Fast < Topics.size(); Fast++)
        {
            if (Topics[Slow] != Topics[Fast])
            {
                Slow++;
                std::swap(Topics[Slow], Topics[Fast]);
            }
        }
        Topics.resize(k);
        return Topics;
    }

};


int main()
{
    int n = 0, k = 0;
    std::vector<int> Topic(n);
    
    for(size_t i = 0; i < n; i++)
    {
        std::cin >> Topic[i];
    }


    return 0;
}