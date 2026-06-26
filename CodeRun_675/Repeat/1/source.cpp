#include <iostream>
#include <vector>

/*

25.06.2026
11:18

Task: We have an adjacency matrix(Size of rows == size of cols), and we need to find the minimum distance from 
one point to another point, as specified by the user.

P.S. | 18.11.2025 | 23:02: - I can not to imagine the whole algorithm in my head. I can rotate this thing.
P.S. | 18.11.2025 | 23:59: - I wanna try to become the best of mine copy
*/

class Solution
{
public:
    int HappyVasya(std::vector<int>& Mushrooms)
    {
        int MaxHappyVasya = 0, HappyMasha = 0;
        int MinMushroomVasya = Mushrooms[0], MaxMushroomMasha = Mushrooms[1]; 
        for(int i = 0; i < Mushrooms.size(); i++)
        {
            int Whoose = i%2;
            if (Whoose == 0)
            {
                MaxHappyVasya += Mushrooms[i];
                if (MinMushroomVasya > Mushrooms[i]) MinMushroomVasya = Mushrooms[i];
            }
            else
            {
                HappyMasha += Mushrooms[i];
                if (MaxMushroomMasha < Mushrooms[i]) MaxMushroomMasha = Mushrooms[i];
            }           
        }

        if (MinMushroomVasya < MaxMushroomMasha)
        {
            MaxHappyVasya -= MinMushroomVasya + MaxMushroomMasha;
            HappyMasha -= MaxMushroomMasha + MinMushroomVasya;
        }

        return MaxHappyVasya - HappyMasha;
    }
};

int main() 
{
    int NumberOfMushrooms = 0;
    std::cin >> NumberOfMushrooms;
    std::vector<int> Mushrooms(NumberOfMushrooms);
    for (auto i : Mushrooms) std::cin >> i;
    Solution Daps;
    std::cout << Daps.HappyVasya(Mushrooms);
	return 0;
}