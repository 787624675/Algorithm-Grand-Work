#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Ϊ�˼򻯴��룬����һЩ�� 
// ԭ���ĺ�������Ϊ���ӣ���Ϊ�ˡ�����֪�⡱ 
#define u upper_bound_u
#define S(x) Sum_X(x)
#define Su(x) Sum_less_than_u(x)
#define S_u(x) Sum_sharp_less_than_u(x)
#define add(x,y) Add_less_than_u(x,y)
#define add2(x,y) Add_ltu_2d(x,y)

// �������Ҫ�õ���һЩ�����ĺ��� 
// �ͺ��� 
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
// ���С��u���Ӽ��� 
// ������Ϣ��
// ���룺����X
// �����X �������Ӽ� Y ��Ԫ��֮�� 
set<int> Sum_less_than_u(set<int> X){
	// TODO: Please implement me;
}
// ���С��u���Ӽ���,����ʾΪ���� (Sum_Y_i, cardinality) ����ʽ 
// ������Ϣ��
// ���룺����X
// ����������ļ��ϣ���������������Ϣ��
// 1. X ���Ӽ� Y_i ��Ԫ��֮�� 
// 2. Y_i �� ���� 
set< vector< int, int> > Sum_sharp_less_than_u(set<int> X){
	// TODO: Please implement me;
}
// ����һ�����ϣ�Ԫ��Ϊ��Element_i = X_i + Y_j <= u ? X_i + Y_j : u;  
set<int> Add_less_than_u(set<int> X, set<int> Y){
	// TODO: Please implement me;
	
}
// ���溯���Ķ�ά��ʽ 
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
