#include <iostream>
#include <vector>

/*

28.07.2026
19:10

Task: The city is an infinite grid. A car starts at intersection (x0, y0) and needs to reach intersection (x1, y1).
At the starting intersection the driver can manually choose any initial direction for free.
After that, at each intersection only two maneuvers are allowed: turn left and make a U-turn.

Idea: Draw a trajectory from one point to another and understand how it depends on dx and dy. Identify special cases.

Pattern: Math / Grid movement / Formula instead of simulation.

Solution:  x ==0 -> 3*(dy-1), y == 0 -> 3*(dx-1), else -> 3*(dx-1)+3*(dy-1)+1

Complexity: O(1)

Brainstorm:

*/

class Solution
{
public:
    long long int NewTrafficLaws(long long int x0, long long int y0, long long int x1, long long int y1)
    {
        long long int dx = std::abs(x1 - x0);
        long long int dy = std::abs(y1 - y0);
        if (dx == 0 && dy == 0) return 0;
        if (dx == 0) return 3*(dy-1);
        if (dy == 0) return 3*(dx-1);
        return 3*(dx-1)+3*(dy-1)+1;
    }
};

int main()
{
    long long int x0 = 0, y0 = 0;
    std::cin >> x0 >> y0;
    long long int x1 = 0, y1 = 0;
    std::cin >> x1 >> y1;

    Solution Daps;
    std::cout << Daps.NewTrafficLaws(x0, y0, x1, y1);
    return 0;
}