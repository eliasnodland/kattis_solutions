#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int main(int argc, char *argv[])
{
	std::map<std::string, bool> words;
	std::string word;
	
	while (std::cin >> word) {
		if (words.find(word) != words.end()) {
			std::cout << "no";
			return 0;
		}
		words[word] = true;
	}

	std::cout << "yes";
	return 0;
}
