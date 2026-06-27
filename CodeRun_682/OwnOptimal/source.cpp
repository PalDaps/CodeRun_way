#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

/*

27.07.2026
15:10

Task: 
A string S is cut into k identical parts. You are given an input array containing these parts in a shuffled order. 
Need to determine the order in which to join them to reconstruct the original string.

Idea: Use a hash map and a queue to store unsorted chunks. Then, slice the input string and look up the substrings in the 
hash table in order.

Pattern: Hash map / String chunks / Handling duplicates with queue.

Solution:

Complexity: O(n)

Brainstorm:

*/


class Solution
{
public:
    std::vector<int> OrderStringSlices(const std::string& FullString, const std::vector<std::string>& StringSlices)
    {
        int CountSlices = StringSlices.size();
        int SizeSubstr = StringSlices[0].size();
        std::vector<int> Out;

        std::unordered_map<std::string, std::queue<int>> OrderSliceToIndex;
        for (int i = 0; i < CountSlices; i++)
        {
            OrderSliceToIndex[StringSlices[i]].push(i+1);
        }

        for (int i = 0; i < CountSlices; i++)
        {
            std::string Substr = FullString.substr(i*SizeSubstr, SizeSubstr);
            
            int Index = OrderSliceToIndex[Substr].front();
            OrderSliceToIndex[Substr].pop();
            Out.push_back(Index);
        }

        return Out;
    }
};

int main()
{
    int StrSize = 0, CountSlices = 0;
    std::cin >> StrSize >> CountSlices;
    std::string FullString;
    std::cin >> FullString;
    std::vector<std::string> StringSlices(CountSlices);
    for (int i = 0; i < CountSlices; i++)
    {
        std::cin >> StringSlices[i];    
    }

    Solution Daps;
    std::vector<int> Out = Daps.OrderStringSlices(FullString, StringSlices);
    for (auto i : Out)
        std::cout << i << " ";

    return 0;
}