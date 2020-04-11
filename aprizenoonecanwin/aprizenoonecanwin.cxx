#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, X;
	std::cin >> n >> X;

	std::vector<int> v(n);
	for (int &k : v) std::cin >> k;
	std::sort(v.begin(), v.end());

	int i = 1;
	while (v[i] + v[i - 1] <= X && i < n) ++i; 

	std::cout << i;

	return 0;
}
