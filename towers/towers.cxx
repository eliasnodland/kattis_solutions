#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

typedef std::vector<float> f32vec;
typedef std::pair<f32vec, std::string> vspair;

f32vec parse(std::string str)
{
	f32vec result;
	std::stringstream ss(str);
	std::string item;
	while (std::getline(ss, item, '^')) { 
		int n = std::stoi(item);
		if (n == 1) break;

		result.push_back(std::log(std::stof(item)));
	}
	return result;
}

int cmp(vspair a, vspair b)
{
	std::cout << a.second << " " << b.second << '\n';
	f32vec an = a.first;
	f32vec bn = b.first;
	float rhs = 1.0f;
	for (int i = 0; i < std::min(an.size(), bn.size()); ++i) {
		rhs = log(rhs) *  bn[i]/an[i];
		if (rhs < 0) return -1;
	}

	for (int i = bn.size(); i < an.size(); ++i) {
		rhs = log(rhs) / an[i];
		if (rhs < 0) return -1;
	}

	for (int i = an.size(); i < bn.size(); ++i) {
		rhs = log(rhs) * bn[i];
		if (rhs < 0) return -1;
	}

	if (1 > rhs) return -1;
	std::cout << rhs << '\n';
	return 1;
}

int main(int argc, char *argv[])
{
	int M;
	std::cin >> M;

	std::vector<vspair> v(M);
	for (int i = 0; i < M; ++i) {
		std::string input;
		std::cin >> input;
		v[i] = std::make_pair(parse(input), input);
	}

	std::sort(v.begin(), v.end(), cmp);

	for (auto p : v) std::cout << p.second << '\n';

	return 0;
}
