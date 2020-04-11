#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	float X;
	std::cin >> X;
	int ans = X * (5280.0 / 4854.0) * 1000.0 + 0.5;
	std::cout << ans;
	return 0;
}
