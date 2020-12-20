#include<math.h>
#include<malloc.h>
#define doublepi 6.2831853071796

struct complex {
	double r;
	double i;
	complex(double real = 0, double imag = 0) :r(real), i(imag) {}
	double abs() { return sqrt(r * r + i * i); }
	complex operator-(const complex& o) { return complex(r - o.r, i - o.i); }
	complex operator*(const complex& o) {
		return complex(r * o.r - i * o.i, r * o.i + i * o.r);
	}
	complex& operator/=(const double o) {
		r /= o;
		i /= o;
		return *this;
	}
	complex& operator+=(const complex& o) {
		r += o.r;
		i += o.i;
		return *this;
	}
	void out() {
		if (r >= 0) printf(" %.4lf", r);
		else printf("%.4lf", r);
		if (i >= 0) printf("+%.4lfi", i);
		else printf("%.4lfi", i);
	}

};

complex W(int k, int n) {
	double t = doublepi * k / n;
	return complex(cos(t), sin(t));
}

int inbit(int i, int L) {
	int res = 0;
	while (L--) {
		res = (res << 1) + (i & 1);
		i /= 2;
	}
	return res;
}
int getL(int n) {
	for (int i = 0; i < 32; i++) {
		if ((1 << i) >= n) return i;
	}
	return 0;
}

void transform(complex* X, complex* Ws, int L) {
	int n = 1 << L;
	for (int m = 1; m <= L; m++) {
		int dist = 1 << (m - 1);
		for (int i = 0; i < n; i += 2 * dist) {

			for (int j = 0; j < dist; j++) {
				int k = i + j;
				int r = j << (L - m);
				complex t = X[k + dist] * Ws[r];
				X[k + dist] = X[k] - t;
				X[k] += t;
			}
		}
	}
}

void fft(complex* src, complex* dst, int n, bool inverse = false) {
	if (src == dst) throw 1;
	int L = getL(n);
	complex* Ws = new complex[n / 2];
	if (inverse) for (int i = 0; i < n / 2; i++) Ws[i] = W(i, n);
	else for (int i = 0; i < n / 2; i++) Ws[i] = W(-i, n);
	for (int i = 0; i < n; i++) dst[i] = src[inbit(i, L)];
	transform(dst, Ws, L);
	if (inverse) for (int i = 0; i < n; i++) src[i] = dst[i].r / n;
	delete[] Ws;
}

void fft2(complex** src, complex** dst, int u, int v, bool inverse = false) {
	if (src == dst) throw 1;
	complex* Ws = new complex[(u > v ? u : v) / 2];
	complex* Work = new complex[u];

	int n = v / 2;
	if (inverse) for (int i = 0; i < n; i++) Ws[i] = W(i, v);
	else for (int i = 0; i < n; i++) Ws[i] = W(-i, v);
	int Ly = getL(v);
	for (int x = 0; x < u; x++) {
		for (int y = 0; y < v; y++) {
			dst[x][y] = src[x][inbit(y, Ly)];
		}
		transform(dst[x], Ws, Ly);
	}

	n = u / 2;
	if (inverse) for (int i = 0; i < n; i++) Ws[i] = W(i, u);
	else for (int i = 0; i < n; i++) Ws[i] = W(-i, u);
	int Lx = getL(u);
	for (int y = 0; y < v; y++) {
		for (int x = 0; x < u; x++) Work[x] = dst[inbit(x, Lx)][y];
		transform(Work, Ws, Lx);
		for (int x = 0; x < u; x++) dst[x][y] = Work[x];
	}

	if (inverse) {
		int uv = u * v;
		for (int i = 0; i < u; i++) {
			for (int j = 0; j < v; j++) {
				dst[i][j] /= uv;
			}
		}
	}
	delete[] Ws;
	delete[] Work;
}
