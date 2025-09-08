#include <iostream>

/*

08.09.2025
15:25

Task: Can a brick of size A×B×C fit through a hole of size N×M

Idea: The task reduces to checking the three faces of the brick. If any face can pass through the hole, the answer is “yes”

Solution: 

Brainstorm:

P.S. I noticed an issue with very easy tasks, which I like to call the “Very Easy Task Trap”

*/

class Soltuion
{
public:
	std::string BruteForce(int A, int B, int C, int D, int E)
	{
		return (B <= D && C <= E) || (B <= E && C <= D) ||
			   (A <= D && C <= E) || (A <= E && C <= D) ||
			   (A <= D && B <= E) || (A <= E && B <= D) ? "YES" : "NO";
	}

	std::string MinEdge(int A, int B, int C, int D, int E)
	{
		int FirstMin = std::min(A, std::min(B, C));
		int SecondMin = A + B + C - FirstMin - std::max(A, std::max(B, C));

		int WindowMin = std::min(D, E);
		int WindowMax = std::max(D, E);

		return FirstMin <= WindowMin && SecondMin <= WindowMax ? "YES" : "NO";
	}
}; 

int main() 
{
	int D = 0, E = 0;
	int A = 0, B = 0, C = 0;
	std::cin >> A >> B >> C >> D >> E;

	Soltuion Daps;
	std::cout << Daps.MinEdge(A, B, C, D, E);
	return 0;
}