#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <climits>

int num(std::string str)
{
	int res = 0;
	for (char c : str)
		res += 1 << (c - 'A');
	return res;
}

int popcount(int n)
{
	std::bitset<sizeof(int) * CHAR_BIT> b(n);
	return b.count();
}

int main()
{
	int R; 
	std::cin >> R;

	std::vector<std::vector<int>> m(R);
	std::vector<int> recitals(R);

	for (int i = 0; i < R; ++i) {
		m[i] = std::vector<int>(R);
		std::string recital;
		std::cin >> recital;
		int r = num(recital);
		recitals[i] = r;

		for (int j = 0; j <= i; ++j) {
			m[i][j] = popcount(recitals[i] & recitals[j]);
			m[j][i] = m[i][j];
		}
	}

	std::vector<bool> c(R, false); // Whether the recital c[i] is completed or not
	int last = 0;
	int current = 0;
	for (int i = 0; i < R; ++i) {
		if (last < m[i][i]) {
			last = m[i][i];
			current = i;
		}
	}

	int sum = 0;
	std::vector<int> o(R);

	for (int i = 0; i < R - 1; ++i) {
		c[current] = true;
		int small = 26;
		int index = 0;

		o[i] = current;

		for (int j = 0; j < R; ++j) {
			if (m[current][j] < small && !c[j]){
				small = m[current][j];
				index = j;
			}
		}

		sum += small;
		current = index;
	}

	o[R - 1] = current;
	
	for (int n : o) std::cout << n << ' ';
	std::cout << ": " << sum << '\n';
		
	return 0;
}
