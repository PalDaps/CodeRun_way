#include <iostream>

/*

26.08.2025
23:20

Task: Three numbers are given. They need to be sorted and the middle number should be output

Idea: Find max and min, then subtract them from the total amount

Solution: if we take into account that there will always be three elements, then we sum everything up and subtract the maximum and minimum

Brainstorm:

P.S. 23:40 Unusual environment CodeRun, and now I also compile code in visual studio code

*/

void MiddleElement(void)
{
	int Array[3] = {0};
	for(int i = 0; i < 3; ++i) std::cin >> Array[i];

	int Min = std::min(Array[0], std::min(Array[1], Array[2]));
	int Max = std::max(Array[0], std::max(Array[1], Array[2]));
	int Middle = Array[0] + Array[1] + Array[2] - Min - Max;

	std::cout << Middle;
}

int main() 
{
	MiddleElement();
	return 0;
}
