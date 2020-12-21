#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include "fft2.hpp"

using namespace std;

#define S(x) Sum_X(x)
#define add(x,y,z) Add_less_than_u(x,y,z)
#define add2(x,y,z) addusharp(x,y,z)
#define asss(w,z) All_Subset_Sums_sharp(w,z)
#define ass(w,z) All_Subset_Sums(w,z)

const int maxn = 2e6 + 5;
const double pi = 3.1415926535898;
int r[maxn * 2];

struct Cpx {  //����
	double x, y;
	Cpx(double t1 = 0, double t2 = 0) { x = t1, y = t2; }
}A[maxn * 2], B[maxn * 2], C[maxn * 2];
Cpx operator +(Cpx a, Cpx b) { return Cpx(a.x + b.x, a.y + b.y); }
Cpx operator -(Cpx a, Cpx b) { return Cpx(a.x - b.x, a.y - b.y); }
Cpx operator *(Cpx a, Cpx b) { return Cpx(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }

void fdft(Cpx* a, int n, int flag) {  
	for (int i = 0; i < n; ++i) if (i < r[i]) swap(a[i], a[r[i]]);
	for (int mid = 1; mid < n; mid <<= 1) {  
		Cpx w1(cos(pi / mid), flag * sin(pi / mid)), x, y;
		for (int j = 0; j < n; j += (mid << 1)) {  
			Cpx w(1, 0);
			for (int k = 0; k < mid; ++k, w = w * w1) {  
				x = a[j + k], y = w * a[j + mid + k];
				a[j + k] = x + y; a[j + mid + k] = x - y;
			}
		}
	}
}


int Sum_X(set<int> X){
	set<int>::iterator it;
	int sum = 0;
    for (it = X.begin(); it != X.end(); it++){
    	cout<<*it<<" ";
    	sum += *it;
    }
    cout<<endl;
    return sum;
	
}
int max_x(set<int> X){
	set<int>::iterator it;
	int max = 0;
    for (it = X.begin(); it != X.end(); it++){
    	// cout<<*it<<" ";
    	if(*it > max){
    		max = *it;
		}
    }
    return max;
}

// Element_i = X_i + Y_j <= u ? X_i + Y_j : u;  
set<int> Add_less_than_u(set<int> X, set<int> Y, int u) {
	int l=0, len = 1;
	set<int> result;
	int n ,m;
	if(X.size() == 0){
		n = 0;
	}else{
		n = *X.rbegin();
	}
	if(X.size() == 0){
		m = 0;
	}else{
		m = *Y.rbegin();
	}
	
	for (int i = 0; i <= n; i++) {
		if (X.count(i)) {
			A[i].x = 1;
		}
		else {
			A[i].x = 0;
		}
	}
	for (int i = 0; i <= m; i++) {
		if (Y.count(i)) {
			B[i].x = 1;
		}
		else {
			B[i].x = 0;
		}
	}
	while (len <= n + m) len <<= 1, ++l;
	for (int i = 0; i < len; ++i)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	fdft(A, len, 1); fdft(B, len, 1);
	for (int i = 0; i < len; ++i) C[i] = A[i] * B[i];
	fdft(C, len, -1);
	for (int i = 0; i <= u; ++i) {
		if ( int(C[i].x / len + 0.5) !=0) {
			result.insert(i);
		}
	}
	len = 1;
	for (int i = 0; i < maxn * 2; i++) {
		r[i] = 0;
		A[i].x = 0;
		A[i].y = 0;
		B[i].x = 0;
		B[i].y = 0;
		C[i].x = 0;
		C[i].y = 0;
	}
	return result;
}

extern set<vector<int> > addusharp(set<vector<int> > X, set<vector<int> > Y,int u);
// General function 
set<vector<int> >  All_Subset_Sums_sharp(set<int> X, int u){
	if(X.size() == 1){
		set<vector<int> > result;
		result.insert(vector<int>(2,0));
		vector<int> temp; 
		temp.push_back(*X.begin());
		temp.push_back(1);
		result.insert(temp);
		return result; 
	}else{
		// 
		set<int> T;
		set<int>::iterator it;
		int count = 0; 
		int n_2 = X.size()/2;
		for (it = X.begin(); it != X.end();count++){
    	//	cout<<*it<<" ";        // 
    		if(count == n_2){
    			break;
			}
    		T.insert(*it);
    		X.erase(it++);
    	}
    	return add2(asss(T,u),asss(X,u),u);
	}
} 
set<int >  All_Subset_Sums(set<int> X, int u){
	int n = X.size();
	int b = sqrt(n*(log(n)/log(10)));
	vector<set<int> > R;
	for(int i = 0 ;i < b; i++){
		set<int> Q_i;
		for(auto itx = X.begin(); itx!=X.end();itx++){
			if((*itx)%b == i%b){
				Q_i.insert(((*itx)-i)/b);
			}
		}
    	set<vector<int> > subqi = asss(Q_i, u/b);
    	set<vector<int> >::iterator it_subqi ;
    	set<int> temp;
		for (it_subqi = subqi.begin(); it_subqi != subqi.end(); it_subqi++){
    		// cout<<*it_s_i<<" ";
    		
    		temp.insert((*it_subqi)[0]*b + (*it_subqi)[1]*i);
    		
    	}
		R.push_back(temp);
	}
	for(int i = 1; i<b; i++){
		R[i] = add(R[i-1],R[i],u);
	}
	return R[b-1];
}
int main(){
	set<int> X;
	int input_x;
	int num,u1;
	cout<<"Please input the size of X:";
	cin>>num;
	cout<<endl;
	for(int i = 0; i < num; i++){
		cin>>input_x;
		X.insert(input_x);
	}
	cout<<"u1:";
	cin>>u1;
	auto res = ass(X,u1);
	for(auto it = res.begin();it!=res.end();it++){
		cout<<*it<<" ";
	}
	
} 
