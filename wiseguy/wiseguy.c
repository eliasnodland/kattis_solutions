#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void muladd(double *dst, double *a, double *b, int len)
{
	for (int i = 0; i < len; ++i) dst[i] += a[i] * b[i];
}

void divd(double *dst, double d, int len)
{
	for (int i = 0; i < len; ++i)
		dst[i] /= d;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int N = 500 + 1;
	double *p = malloc(N * N * sizeof(double));

	for (int h = 0; h < N; ++h) {
		p[0*N + h] = 1.0;
		p[1*N + h] = 1.0;
	}

	for (int n = 2; n < N; ++n) {
		for (int l = 0; l < n; ++l) {
			int r = n - l - 1;
			muladd(p+N*n+1, p+N*l, p+N*r, N - 1);
		}
		divd(p+N*n+1, (double)n, N-1);
	}

	double *E = malloc(N * sizeof(double));

	for (int n = 0; n < N; ++n) {
		double s = 0.0;
		for (int h = N - 1; h > 0; --h) {
			p[N*n+h] -= p[N*n+h-1];
			s += p[N*n + h] * (double)h;
		}
		E[n] = s;
	}

	int T;
	if (scanf("%d", &T) < 1) return 0;
	for (int i = 0; i < T; ++i) {
		int n;
		if (scanf("%d", &n) < 1) return 0;
		printf("%.6f\n", E[n]);
	}

	return 0;
}
