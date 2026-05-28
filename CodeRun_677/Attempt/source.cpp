#include <iostream>

/*

05.10.2025
14:17

Task: We have a string s. We can swap pairs of letters. We need to determine how many different combinations can be generated from the original string by 
swapping pairs of letters

Idea: Array of frequencies. And count how many specific letters can be swapped for other letters

Solution:

Brainstorm:

*/

class Solution
{
public:
	long long int Cybersecurity(std::string Password)
	{
        long long int Table[26] = {0};
        long long int Max = 0;
        long long int Size = Password.size();

        for(size_t i = 0; i < Size; i++)
        {
            long long int Index = Password[i] - 'a';
            Table[Index]++;
        }

        long long int CountPrevLetters = 0;

        for(size_t i = 0; i < 26; i++)
        {
            if(Table[i])
            {
                long long int AnotherLetters = Size - Table[i] - CountPrevLetters;
                Max = Max + Table[i]*AnotherLetters;
                CountPrevLetters += Table[i];
            }
        }

        return Max;
	}

};

int main() 
{
    std::string Password = "";
    std::cin >> Password;
    Solution Daps;
    std::cout << Daps.Cybersecurity(Password) + 1;
}
