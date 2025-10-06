#include <iostream>

/*

04.10.2025
18:06

Task: There are a six parameters:
a - distance between home and supermarket
b - distance between home and pickup point
c - distance between supermarket and pickup point
Vo - pure velocity
V1 - velocity with products or package
V2 - velocity with products and package

We need to find minimal time for bring at home products and package

Idea: BruteForce, however, it is necessary to first calculate the minimum distances to the points

Solution:
First way home: -> supermarket -> pickup point -> home
Second way home: -> supermarket -> home -> pickup point -> home
Third way home: -> pickup point -> home -> supermarket -> home
Fourth way home: -> pickup point -> supermarket -> home
Fifth way home: -> supermarket -> pickup point -> supermarket -> home
Sixth way home: -> pickup point -> supermarket -> pickup point -> home
Seventh way with skip: home -> supermarket -> pickup point -> supermarket -> home
Eighth way home with skip: home -> pickup point -> supermarket -> pickup point -> home

How to understand that this is an exhaustive bruteforce?)

P.S. | 05.10.2025 | 12:33: If we need to add some points in this task, is graph pattern. 

Brainstorm:

*/

class SolutionBruteForce
{
public:
	double MomsErrands(double a, double b, double c,
                       double v0, double v1, double v2)
	{
        double MinimalA = std::min(a, b + c);  
        double MinimalB = std::min(b, a + c);  
        double MinimalC = std::min(c, a + b);

        a = MinimalA;
        b = MinimalB;
        c = MinimalC;

        // First way home: -> supermarket -> pickup point -> home
        double FirstWay = a/v0 + c/v1 + b/v2;
        // Second way home -> supermarket -> home -> pickup point -> home
        double SecondWay = a/v0 + a/v1 + b/v0 + b/v1;
        // Third way home -> pickup point -> home -> supermarket -> home
        double ThirdWay = b/v0 + b/v1 + a/v0 + a/v1;
        // Fourth way home -> pickup point -> supermarket -> home
        double FourthWay = b/v0 + c/v1 + a/v2;
        // Fifth way home -> supermarket -> pickup point -> supermarket -> home
        double FifthWway = a/v0 + c/v1 + c/v2 + a/v2;
        // Sixth way home -> pickup point -> supermarket -> pickup point -> home
        double SixthWay = b/v0 + c/v1 + c/v2 + b/v2;
        // Seventh way with skip home -> supermarket -> pickup point -> supermarket -> home
        double SeventhWay = a/v0 + c/v0 + c/v1 + a/v2;
        // Eighth way home with skip home -> pickup point -> supermarket -> pickup point -> home
        double EighthWay = b/v0 + c/v0 + c/v1 + b/v2;

        double MinOne = std::min(FirstWay, SecondWay);
        double MinTwo = std::min(ThirdWay, FourthWay);
        double MinThree = std::min(FifthWway, SixthWay);
        double MinFour = std::min(SeventhWay, EighthWay);

        return std::min(std::min(MinOne, MinTwo), std::min(MinThree, MinFour));
	}

};

int main() 
{
    double a = 0, b = 0, c = 0, v0 = 0, v1 = 0, v2 = 0;
    std::cin >> a >> b >> c >> v0 >> v1 >> v2;
    SolutionBruteForce Daps;
    std::cout << Daps.MomsErrands(a, b, c, v0, v1, v2);
	return 0;
}
