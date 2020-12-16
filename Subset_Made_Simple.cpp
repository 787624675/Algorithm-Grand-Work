#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

// 为了简化代码，定义一些宏 
// 原来的函数名较为复杂，是为了“见名知意” 
#define u upper_bound_u
#define S(x) Sum_X(x)
#define Su(x,y) Sum_less_than_u(x,y)
#define S_u(x,y) Sum_sharp_less_than_u(x,y)
#define add(x,y) Add_less_than_u(x,y)
#define add2(x,y) Add_ltu_2d(x,y)
#define asss(x,y) All_Subset_Sums_sharp(x,y)
#define ass(x,y) All_Subset_Sums(x,y)

// 定义后需要用到的一些基本的函数 
// 和函数 
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
    	if(p*it > max){
    		max = *it;
		}
    }
    return max;
}
// 求和小于u的子集合 
// 参数信息：
// 输入：集合X
// 输出：X 的所有子集 Y 的元素之和 
set<int> Sum_less_than_u(set<int> X, int u){
	// TODO: Please implement me;
}
// 求和小于u的子集合,并表示为向量 (Sum_Y_i, cardinality) 的形式 
// 参数信息：
// 输入：集合X
// 输出：向量的集合，向量包含两个信息：
// 1. X 的子集 Y_i 的元素之和 
// 2. Y_i 的 基数 
set< vector< int, int> > Sum_sharp_less_than_u(set<int> X, int u){
	// TODO: Please implement me;
}
// 构造一个集合，元素为：Element_i = X_i + Y_j <= u ? X_i + Y_j : u;  
set<int> Add_less_than_u(set<int> X, set<int> Y){
	// TODO: Please implement me;
	
}
// 上面函数的二维形式 
set<vector<int, int> > Add_ltu_2d(set<int, int> X, set<int, int> Y){
	// TODO: Please implement me;
	
}
// General function 
set<vector<int, int> >  All_Subset_Sums_sharp(set<int> X, int upper_bound_u){
	if(X.size() == 1){
		set<vector<int, int> > result;
		result.insert(vector<int, int>(0,0));
		result.insert(vector<int, int>(*X.begin(),1));
		return result; 
	}else{
		// 令 T 为 S 的任意一个 基数为 n/2的子集
		set<int> T<int>;
		set<int>::iterator it;
		int count = 0; 
		int n_2 = X.size()/2;
		for (it = X.begin(); it != X.end(); it++,count++){
    	//	cout<<*it<<" ";        // 随时为测试做准备 
    		if(count == n_2){
    			break;
			}
    		T.insert(it);
    		S.erase(it);
    	}
    	return add2(asss(T,u),asss(S,u));
	}
} 
set<vector<int, int> >  All_Subset_Sums(set<int> X, int upper_bound_u){
	int n = X.size();
	int b = aqrt(n*log(n));
	vector<set<vector<int, int> > > R;
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
		// 取交集 
		set_intersection(X.begin(),X.end(),Smns.begin(),Smns.end(),inserter(S_i,S_i.end()));
		set::iterator it_s_i ;
		for (it_s_i = S_i.begin(); it_s_i != S_i.end(); it_s_i++){
    		// cout<<*it_s_i<<" ";
    		Q_i.insert((*it_s_i - i)/b);	
    	}
    	int subqi = asss(Q_i, u/b);
    	set::iterator it_subqi ;
    	
		for (it_subqi = subqi.begin(); it_subqi != subqi.end(); it_subqi++){
    		// cout<<*it_s_i<<" ";
    		set<vector<int, int> > temp;
    		temp.insert(vector<int, int>((*it_subqi)[0]*b, (*it_subqi)[1]*i));
    		R.push_back(temp);
    	}
	}
	for(int i = 1; i<b; i++){
		R[i] = add2(R[i-1],R[i]);
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
