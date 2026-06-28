#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

/*

28.07.2026
16:30

Task: A string S is cut into k identical parts. You are given an input array containing these parts in a shuffled order. 
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
    std::vector<int> CutStr(std::string& Fullstring, std::vector<std::string>& SubStrs)
    {
        int SizeSubStr = SubStrs[0].size();
        int SubStrCount = SubStrs.size();

        std::unordered_map<std::string, std::queue<int>> SubStrToIndex;
        
        for (int i = 0; i < SubStrCount; i++)
        {
            SubStrToIndex[SubStrs[i]].push(i+1);
        }
        
        std::vector<int> Result;

        for (int i = 0; i < SubStrCount; i++)
        {
            std::string SubStr = Fullstring.substr(i*SizeSubStr, SizeSubStr);

            int Index = SubStrToIndex[SubStr].front();
            SubStrToIndex[SubStr].pop();
            Result.push_back(Index);
        }

        return Result;
    }
};

int main() 
{
    int StrSize = 0, SubStrCount = 0;
    std::cin >> StrSize >> SubStrCount;
    std::string FullString;
    std::cin >> FullString;
    std::vector<std::string> SubStrs(SubStrCount);
    for (int i = 0; i < SubStrCount; i++)
        std::cin >> SubStrs[i];

    Solution Daps;
    std::vector<int> Out = Daps.CutStr(FullString, SubStrs); 
    for (auto i : Out)
        std::cout << i << " ";
	return 0;
}
