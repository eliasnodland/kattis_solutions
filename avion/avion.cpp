#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string input;
	int i = 1;
	bool found = false;
	while (std::cin >> input) {
		if (input.find("FBI") != std::string::npos) {
		       	std::cout << i << '\n'; 
			found = true;
		}
		++i;
	}

	if (!found) std::cout << "HE GOT AWAY!" << '\n';

	return 0;
}
