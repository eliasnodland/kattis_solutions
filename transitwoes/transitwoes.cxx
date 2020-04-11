#include <iostream>
#include <vector>
#include <unistd.h>

int main(int argc, char *argv[])
{
	usleep(990000);

	int s, t, n;
	std::cin >> s >> t >> n;

	std::vector<int> walk_time(n + 1);
	for (int &d : walk_time) std::cin >> d;

	std::vector<int> ride_time(n);
	for (int &b : ride_time) std::cin >> b;

	std::vector<int> ride_interval(n);
	for (int &c : ride_interval) std::cin >> c;

	for (int i = 0; i < n; ++i) {
		int d = walk_time[i];
		int b = ride_time[i];
		int c = ride_interval[i];

		s += d;
		if (s % c > 0) s += c - (s % c);
		s += b;
	}

	s += walk_time[n];

	if (s < t) std::cout << "yes\n";
	else std::cout << "no\n";

	return 0;
}
