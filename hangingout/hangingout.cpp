#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int L, x;
	std::cin >> L >> x;

	int total = 0;
	int rejected = 0;
	for (int i = 0; i < x; ++i) {
		std::string e;
		int p;
		std::cin >> e >> p;
		if (e.compare("enter") == 0) {
			if (total + p > L) ++rejected;
			else total += p;
		} else {
			total -= p;
		}
	}

	std::cout << rejected;
	return 0;
}
