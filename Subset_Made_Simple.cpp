#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 为了简化代码，定义一些宏 
// 原来的函数名较为复杂，是为了“见名知意” 
#define u upper_bound_u
#define S(x) Sum_X(x)
#define Su(x) Sum_less_than_u(x)
#define S_u(x) Sum_sharp_less_than_u(x)
#define add(x,y) Add_less_than_u(x,y)
#define add2(x,y) Add_ltu_2d(x,y)

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
// 求和小于u的子集合 
// 参数信息：
// 输入：集合X
// 输出：X 的所有子集 Y 的元素之和 
set<int> Sum_less_than_u(set<int> X){
	// TODO: Please implement me;
}
// 求和小于u的子集合,并表示为向量 (Sum_Y_i, cardinality) 的形式 
// 参数信息：
// 输入：集合X
// 输出：向量的集合，向量包含两个信息：
// 1. X 的子集 Y_i 的元素之和 
// 2. Y_i 的 基数 
set< vector< int, int> > Sum_sharp_less_than_u(set<int> X){
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
set<vector<int, int> >  All_Subset_Sums(set<int> X, int upper_bound_u){
	if(X.size() == 1){
		set<vector<int, int> > result;
		result.insert(vector<int, int>(0,0));
		result.insert(vector<int, int>(*X.begin(),1));
		return result; 
	}else{
		
	}
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
