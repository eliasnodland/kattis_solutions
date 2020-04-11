#include <iostream>

int main(int argc, char *argv[])
{
	int n, h, v;
	std::cin >> n >> h >> v;
	
	h = std::max(h, n - h);
	v = std::max(v, n - v);
	std::cout << h * v * 4;
	return 0;
}
