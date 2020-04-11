#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>

size_t MAXN = 4e5 + 5;
typedef std::int64_t i64;
typedef std::int32_t i32;

void change(std::vector<std::complex<double>> &y, int len)
{
	for (int i = 1, j = len/2; i < len-1; ++i) {
		if (i < j) std::swap(y[i], y[j]);
		int k = len/2;
		while (j >= k) j -= k /= 2;
		if (j < k) j += k;
	}
}

void fft(std::vector<std::complex<double>> &y, int len, int on)
{
	change(y, len);
	for (int h = 2; h <= len; h *= 2) {
		double c = -on * 2 * M_PI / h;
		std::complex<double> wn(std::cos(c), std::sin(c));
		for (int j = 0; j < len; j += h) {
			std::complex<double> w(1, 0);
			for (int k = j; k < j + h / 2; ++k) {
				std::complex<double> u = y[k];
				std::complex<double> t = w * y[k + h / 2];
				y[k] = u + t;
				y[k + h / 2] = u - t;
				w *= wn;
			}
		}
	}
}

int main()
{
	std::vector<complex<double>> x1(MAXN), x(MAXN);
	std::vector<i64> ans(MAXN, 0);
	std::vector<i32> a(MAXN);
	std::vector<i64> num(MAXN, 0);
	std::vector<i64> sun(MAXN);

	int n;
	std::cin >> n;

	int m = 0;

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i] == 0) ++m;
		a[i] += 50000;
		++num[a[i]];
	}

	std::sort(a.begin(), a.begin() + n);

	int len1 = a[n - 1] + 1;
	int len = 1;

	/* Take the nexg power of 2 larger than len1 */
	while (len < 2 * len1) len *= 2;

	for (int i = 0; i < len1; ++i) { 
		x1[i].real = num[i];
		x1[i].imag = 0;
	}

	for (int i = len1; i < len; ++i) {
		x1[i].real = 0;
		x1[i].imag = 0;
	}

	fft(x1, len, 1);

	for (int i = 0; i < len; ++i) x[i] = x1[i] * x1[i];

	fft(x, len, -1);

	for (int i = 0; i < len; ++i) ans[i] = (i64)(x[i].real + 0.5);

	for (int i = 0; i < n; ++i) --ans[a[i] + a[i]];

	i64 cnt = 0;
	for (int i = 0; i < n; ++i) cnt += ans[a[i]+50000];

	cnt -= (i64)2 * m * (n - 1);
	std::cout << cnt << '\n';
	return 0;
}
