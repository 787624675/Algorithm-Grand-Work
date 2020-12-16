#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

#define S(x) Sum_X(x)
#define add(x,y,z) Add_less_than_u(x,y,z)
#define add2(x,y) Add_ltu_2d(x,y)
#define asss(w,z) All_Subset_Sums_sharp(w,z)
#define ass(w,z) All_Subset_Sums(w,z)

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
set<int> Add_less_than_u(set<int> X, set<int> Y, int u){
	// TODO: Please implement me;
	set<int> result;
	
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
