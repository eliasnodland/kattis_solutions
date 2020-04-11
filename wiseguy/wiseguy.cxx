/* This code is the solution to the problem found at
 * https://open.kattis.com/problems/wiseguy/
 * It can likely be optimized further by doing some of the vector operations
 * (mul, div, add) in place instead of copying, but this runs fast enough for
 * most anything. 

 * Further optimization might include reducing the scope of the mul, add, and
 * div operations as for some n all results after res[n] are known.

 * The algorithm runs in O(n^3) time and has a space complexity of O(n^2). It
 * runs in just under 1 second for n = 1400 on an intel core i7-1065G7 

 * The algorithm is single threaded, but lends itself nicely to multithreading.
 * Either the functions add, mul, and sub could be multithreaded, each thread
 * handling some part of any vector, or the
 * distribution of running these functions could be multithreaded, each thread
 * handling an operation on two vectors. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

/* Adds two vectors a and b element by element */
std::vector<double> add(const std::vector<double> &a,
		        const std::vector<double> &b)
{
	std::vector<double> res(a);
	for (int i = 0; i < res.size(); ++i) res[i] += b[i];
	return res;
}

/* Multiplies two vectors a and b element by element */
std::vector<double> mul(const std::vector<double> &a,
		        const std::vector<double> &b)
{
	std::vector<double> res(a);
	for (int i = 0; i < res.size(); ++i) res[i] *= b[i];
	return res;
}

/* Divides every element in a vector a by the number d */
std::vector<double> div(const std::vector<double> &a, double d)
{
	std::vector<double> res(a);
	for (int i = 0; i < res.size(); ++i) res[i] /= d;
	return res;
}

int main()
{
	const int N = 4000 + 1;
	std::vector<std::vector<double>> p(N);

	/* Initialize table with known probabilities 
	 * p[n][h] = P(H <= h) The probability that a tree of n nodes has a
	 * height equal to or less than h */
	p[0] = std::vector<double>(N, 1.0);
	p[1] = std::vector<double>(N, 1.0);

	/* Calculate the unknown probabilities using the known probabilities
	 * P(H <= h) = P(L <= h-1)*P(R <= h-1)
	 * where H is the height of the tree, L is the height of the left
	 * subtree and R is the height of the right subtree. */
	for (int n = 2; n < N; ++n) {
		/* Init a new vector to store the result */
		std::vector<double> res(N, 0.0);
		for (int l = 0; l < n; ++l) {
			int r = n - l - 1;
			res = add(res, mul(p[l], p[r]));
		}

		res = div(res, n); // Divide the result by n

		/* Shift the result by 1 to add 1 to every height */
		std::rotate(res.begin(), res.end() - 1, res.end());
		res[0] = 0;

		p[n] = res;
	}

	/* Reverses the accumulative probabilities for every N to get P(H)
	 * P(H = h) = P(H <= h) - P(H <= h - 1)
	 * The result is p[n][h] = P(H = h) The probability that a tree of n
	 * nodes has a height strictly equal to h */
	for (int n = 0; n < N; ++n)
		for (int h = N - 1; h > 0; --h) p[n][h] -= p[n][h - 1];

	/* For every n, multiplies the probability of the height h with the
	 * height and sums to get the expected height for a tree of n nodes */
	std::vector<double> e(N);
	for (int n = 0; n < N; ++n) {
		double s = 0.0;
		for (int h = 0; h < N; ++h) s += p[n][h] * (double)h;
		e[n] = s;
	}

	/* The height of a tree with no nodes is -1. It is just included for
	 * completeness and is not required for the submission */
	e[0] = -1.0;

	std::cout << std::fixed;
	std::cout << std::setprecision(6);
	std::cout << "n,\te\n";
	for (int i = 0; i < N; ++i) std::cout << i << ",\t" << e[i] << '\n';

	return 0;
}
