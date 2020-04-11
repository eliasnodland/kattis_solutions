#include <iostream>
#include <iomanip>
#include <cmath>

/* Always go one of the diagonal directions first, then one of the normal
 * directions. E.g NE 25, N 20; */
int main()
{
	long double r, x, y, X, Y;
	x = 0.0;
	y = 75.0;
	X = 25.0;
	Y = 50.0;

	long double dx = x - X;
	long double dy = y - Y;
	long double d = std::sqrt(dx*dx + dy*dy);

	std::cin >> r >> x >> y >> X >> Y;

	std::cout << std::fixed;
	std::cout << std::setprecision(12);
	std::cout << d;
	
	return 0;
}
