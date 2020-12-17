#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 2e6 + 5;
const double pi = 3.1415926535898;
int t, n, m, len = 1, l, r[maxn * 2];

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

inline int getint(int& x) {
	char c; int flag = 0;
	for (c = getchar(); !isdigit(c); c = getchar())
		if (c == '-') flag = 1;
	for (x = c - 48; c = getchar(), isdigit(c);)
		x = (x << 3) + (x << 1) + c - 48;
	return flag ? x : -x;
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
	set<int> result;
	int n, m; //n for X m for Y
	n = *X.rbegin();
	m = *Y.rbegin();
	A[0].x = 0;
	B[0].x = 0;
	for (int i = 1; i <= n; i++) {
		if (X.count(i)) {
			A[i].x = 1;
		}
		else {
			A[i].x = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
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
		//printf("%d ", int(C[i].x / len + 0.5));
		if ( int(C[i].x / len + 0.5) !=0) {
			result.insert(i);
		}
	}
	len = 1;
	return result;
}

set<vector<int> > Add_ltu_2d(set<vector<int> > X, set<vector<int> > Y){
	// TODO: Please implement me;
	
}
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
		for (it = X.begin(); it != X.end(); it++,count++){
    	//	cout<<*it<<" ";        // 
    		if(count == n_2){
    			break;
			}
    		T.insert(*it);
    		X.erase(*it);
    	}
    	return add2(asss(T,u),asss(X,u));
	}
} 
set<int >  All_Subset_Sums(set<int> X, int u){
	int n = X.size();
	int b = sqrt(n*log(n));
	vector<set<int> > R;
	for(int i = 0 ;i < b; i++){
		set<int> S_i;
		set<int> Q_i;
		
		set<int> Smns; // same_mod_nums
		int max = max_x(X); 
		int smn = abs(i - b); // same_mod_num
		while(smn <= max){
			Smns.insert(smn);
			smn += b;
		}
		//
		set_intersection(X.begin(),X.end(),Smns.begin(),Smns.end(),inserter(S_i,S_i.end()));
		set<int>::iterator it_s_i ;
		for (it_s_i = S_i.begin(); it_s_i != S_i.end(); it_s_i++){
    		// cout<<*it_s_i<<" ";
    		Q_i.insert((*it_s_i - i)/b);	
    	}
    	set<vector<int> > subqi = asss(Q_i, u/b);
    	set<vector<int> >::iterator it_subqi ;
    	
		for (it_subqi = subqi.begin(); it_subqi != subqi.end(); it_subqi++){
    		// cout<<*it_s_i<<" ";
    		set<int> temp;
    		temp.insert((*it_subqi)[0]*b + (*it_subqi)[1]*i);
    		R.push_back(temp);
    	}
	}
	for(int i = 1; i<b; i++){
		R[i] = add(R[i-1],R[i],u);
	}
	return R[b-1];
}
int main(){
	set<int> X;
	int input_x;
	int num;
	cout<<"Please input the size of X:";
	cin>>num;
	cout<<endl;
	for(int i = 0; i < num; i++){
		cin>>input_x;
		X.insert(input_x);
	}
	int sum_result = Sum_X(X);
	cout<<sum_result<<endl;
	
} 
