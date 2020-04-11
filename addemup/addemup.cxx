/* The problem text for this solution is found at 
 * https://open.kattis.com/problems/addemup
 *
 * The task is solved by reading in all the v or "cards" and assigning
 * each of them an ID, this will be important later.
 * If the card can be flipped and still reads a valid number, that number is
 * added to the list with the same ID.
 *
 * The list is then sorted by value and the algorithm is run to find a pair that
 * adds up to s.
 *
 * If a pair of v add up, the ID must also be checked to verify they are
 * not in fact the same card. If they are not, a simple YES is printed.
 *
 * If no valid combination is found. NO is printed.  */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>


/* Function to rotate a number 180 degrees (Last digit comes first and is only
 * valid if it can be read in this state.) */
int flip(int n) 
{
	/* When a number i is flipped upside down it becomes another number 
	 * flipped[i]. If this number is invalid then flipped[i] is -1 */
	int flipped[] = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6}; 

	int result = 0; /* The accumulative resulting number. */
	while (n > 0) { /* This loop builds the flipped number */
		/* If one of the digits can not be flipped then return -1 */
		if (flipped[n%10] < 0) return -1;
		result *= 10;
		result += flipped[n%10];
		n /= 10;
	}
	return result;
}

int main(int argc, char *argv[])
{
	std::vector<std::pair<int, int>> v;
	int n, s;
	std::cin >> n >> s;
	v.reserve(2 * n); /* Reserve space for v */

	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		if (x < s) v.push_back(std::make_pair(x, i));

		/* Flip number and if valid, add to list */
		int fx = flip(x);
		if (fx > 0 && fx != x && fx < s) 
			v.push_back(std::make_pair(fx, i));
	}

	std::sort(v.begin(), v.end());
	int i = 0, j = v.size() - 1;
	j = std::upper_bound(v.begin(), v.end(), 
			     std::make_pair(s - v[i].first, -1)) - v.begin();

	i = std::lower_bound(v.begin(), v.end(), 
			     std::make_pair(s - v[j].first, -1)) - v.begin() - 1;

	while (i != j) {
		int r = v[i].first + v[j].first;
		if (r > s) --j;
		if (r < s) ++i;
		if (r == s) {
			if (v[i].second != v[j].second) {
				std::cout << "YES\n";
				return 0;
			}
			++i;
		}
	}

	std::cout << "NO\n";
	return 0;
}
