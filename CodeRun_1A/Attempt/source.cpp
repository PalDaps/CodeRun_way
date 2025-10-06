#include <iostream>
#include <vector>

/*

02.10.2025
10:07

Task: First, a number is given, which determines the maximum number of mushrooms. Then the weight of each mushroom is given.
The mushrooms are distributed between Vasya and Masha according to the following principle: odd-numbered ones go to Vasya, 
even-numbered ones to Masha. Vasya's happiness is defined as the total weight of Vasya's mushrooms minus the total weight of Masha's mushrooms. 
Vasya has the right to swap two mushrooms once. It is necessary to find the maximum happiness of Vasya.

Idea: Calculate the total weight of Vasya's mushrooms, calculate the total weight of Masha's mushrooms. Replace Vasya's smallest mushroom with Masha's largest mushroom. 
Update the maximum weights and calculate the difference.

Solution:

P.S. It is possible to do without a vector and only with two additional variables, TotalMasha and TotalVasya. But in my opinion, the readability of the code 
will be much lower this way.

Brainstorm:

*/

class SolutionBruteForce
{
public:
	int HappyVasya(std::vector<int>& Mushrooms)
	{
        int Size = Mushrooms.size();
        int TotalVasya = 0, TotalMasha = 0;
        int MinVasya = Mushrooms[0], MaxMasha = Mushrooms[1];
        for(size_t i = 0; i < Size; i++)
        {
            bool Whose = i%2;
            if (Whose == 0)
            {
                TotalVasya += Mushrooms[i];
                if (Mushrooms[i] < MinVasya) MinVasya = Mushrooms[i];

            }
            else if(Whose == 1)
            {
                TotalMasha += Mushrooms[i];
                if (Mushrooms[i] > MaxMasha) MaxMasha = Mushrooms[i];
            }
        }

        if (MinVasya < MaxMasha)
        {
            TotalVasya = TotalVasya - MinVasya + MaxMasha;
            TotalMasha = TotalMasha - MaxMasha + MinVasya;
        }

        return TotalVasya - TotalMasha;
	}

};

int main() 
{
	int CountMushrooms = 0;
    std::cin >> CountMushrooms;
    std::vector<int> Mushrooms(CountMushrooms);

    for(size_t i = 0; i < CountMushrooms; i++)
        std::cin >> Mushrooms[i];

    SolutionBruteForce Daps;
    std::cout << Daps.HappyVasya(Mushrooms);
	return 0;
}
