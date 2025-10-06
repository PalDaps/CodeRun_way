#include <iostream>
#include <vector>
#include <set>

/*

05.10.2025
16:29

Task: The first line specifies two numbers: n—the number of problems created by people and k—the number of problems required in the contest. The second line 
lists n numbers, where each number determines the topic to which the i-th problem belongs (numbering starts with 1).

Idea: Use a set to select unique values ​​from the initial vector. Then form a new vector based on length k

Solution:

Brainstorm:

*/

class Solution
{
public:
	std::vector<int> QualifyingСontest(std::vector<int>& Tasks, int k)
	{
        std::set<int> UniqueTasks(Tasks.begin(), Tasks.end());

        int Size = UniqueTasks.size();

        std::vector<int> Сontest;

        for(auto i : UniqueTasks)
        {
            if (Сontest.size() >= k) break;
            Сontest.push_back(i);
        }

        for(auto i : Tasks)
        {
            if (Сontest.size() >= k) break;
            Сontest.push_back(i);
        }

        return Сontest;
	}

};

int main() 
{
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> Task(n);
    for(size_t i = 0; i < n; i++)
    {
        std::cin >> Task[i];
    }

    Solution Daps;
    std::vector<int> Сontest = Daps.QualifyingСontest(Task, k);

    std::cout << "Answer" << std::endl;
    
    for(size_t i = 0; i < Сontest.size(); i++)
    {
        std::cout << Сontest[i] << " ";
    }
}
