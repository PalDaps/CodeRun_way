#include <iostream>
#include <vector>
#include <set>

/*

05.10.2025
16:29

Task: The first line specifies two numbers: n—the number of problems created by people and k—the number of problems required in the contest. The second line 
lists n numbers, where each number determines the topic to which the i-th problem belongs (numbering starts with 1).

Idea: Set for storing unique task topics. A vector with a boolean type for tracking which tasks can be added after the unique ones

Solution:

Brainstorm:

*/

class Solution
{
public:
	std::vector<int> QualifyingСontest(std::vector<int>& Tasks, int k)
	{
        int Size = Tasks.size();

        std::set<int> UniqueTasks;
        std::vector<bool> UsedProblem(Size);
        std::vector<int> Сontest;

        for(size_t i = 0; i < Size; i++)
        {
            int Task = Tasks[i];
            if(!UniqueTasks.count(Task))
            {
                UniqueTasks.insert(Task);
                UsedProblem[i] = true;
            }
        }

        for(auto UniqueTask : UniqueTasks)
        {
            if(Сontest.size() >= k) break;
            
            Сontest.push_back(UniqueTask);
        }

        for(size_t i = 0; i < Size; i++)
        {
            if(Сontest.size() >= k) break;

            if(!UsedProblem[i]) Сontest.push_back(Tasks[i]);
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
    
    for(size_t i = 0; i < Сontest.size(); i++)
    {
        std::cout << Сontest[i] << " ";
    }
}
