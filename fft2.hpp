#include<iostream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
#include"fft.hpp"

const int MAX2D = 1024;

complex** X = new complex * [MAX2D], ** x = new complex * [MAX2D], ** z = new complex * [MAX2D];
complex** Y = new complex * [MAX2D], ** y = new complex * [MAX2D];

void show(complex** X, int u, int v) {
	for (int i = 0; i < u; i++)
	{
		for (int j = 0; j < v; j++) {
			X[i][j].out();
			cout << " ";
		}
		cout << endl;
	}
}

set<vector<int>> addusharp(set<vector<int>> Xin, set<vector<int>> Yin, int u) {
	int Xuin=-1, Xvin=-1;
	int Yuin = -1, Yvin = -1;
	for (int i = 0; i < MAX2D; i++) {
		X[i] = new complex[MAX2D];
		x[i] = new complex[MAX2D];
		Y[i] = new complex[MAX2D];
		y[i] = new complex[MAX2D];
		z[i] = new complex[MAX2D];
	}
	for (int i = 0; i < MAX2D; i++) {
		for (int j = 0; j < MAX2D; j++) {
			X[i][j] = complex(0, 0);
			x[i][j] = complex(0, 0);
		}
	}
	for (set<vector<int>>::iterator it = Xin.begin(); it != Xin.end(); it++) {
		if ((*it)[0] > Xuin) {
			Xuin = (*it)[0];
		}
		if ((*it)[1] > Xvin) {
			Xvin = (*it)[1];
		}
		x[(*it)[0]][ (*it)[1] ]= complex(1,0);
	}
	for (int i = 0; i < MAX2D; i++) {
		for (int j = 0; j < MAX2D; j++) {
			Y[i][j] = complex(0, 0);
			y[i][j] = complex(0, 0);
		}
	}
	for (set<vector<int>>::iterator it = Yin.begin(); it != Yin.end(); it++) {
		if ((*it)[0] > Yuin) {
			Yuin = (*it)[0];
		}
		if ((*it)[1] > Yvin) {
			Yvin = (*it)[1];
		}
		y[(*it)[0]][(*it)[1]] = complex(1, 0);
	}

	int XYu = pow(2, 1+ceil(log(Xuin + Yuin) / log(2)));
	int XYv = pow(2, 1+ceil(log(Xvin + Yvin) / log(2)));

	//show(x, XYu, XYv);

	//cout << endl;

	fft2(x, X, XYu, XYv);
	fft2(y, Y, XYu, XYv);

	for (int i = 0; i < XYu; i++) {
		for (int j = 0; j < XYv; j++) {
			X[i][j] = X[i][j] * Y[i][j];
		}
	}

	fft2(X, z, XYu, XYv, true);
	//cout << "ifft:" << endl;
	//show(z, XYu, XYv);

	set < vector<int> > result;

	for (int i = 0; i < XYu; i++) {
		for (int j = 0; j < XYv; j++) {
			if (z[i][j].r >0.0001) {
				vector<int>t = {i, j};
				// cout << i << ' ' << j<<"      ";
				result.insert(t);
			}
		}
	}

	for (int i = 0; i < MAX2D; i++) {
		delete[] X[i];
		delete[] x[i];
		delete[] Y[i];
		delete[] y[i];
		delete[] z[i];
	}

	return result;
}


// int main() {

// 	vector<int> a = { 1,1 };
// 	vector<int> b = { 2,1 };
// 	vector<int> c = { 3,1 };
// 	vector<int> e = { 2,1 };
// 	vector<int> f = { 4,1 };
// 	vector<int> g = { 10,1 };

// 	set<vector<int>> S1 = { a,b,c };
// 	set<vector<int>> S2 = { e,f,g };

// 	addusharp(S1, S2, 100);
// 	addusharp(S2, S1, 100);

// }