#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
	std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int max = *std::max_element(a.begin(), a.end() - 2);
	std::cout << max << '\n';
	return 0;
}
