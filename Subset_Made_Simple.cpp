#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

// Ϊ�˼򻯴��룬����һЩ�� 
// ԭ���ĺ�������Ϊ���ӣ���Ϊ�ˡ�����֪�⡱ 
#define u upper_bound_u
#define S(x) Sum_X(x)
#define Su(x,y) Sum_less_than_u(x,y)
#define S_u(x,y) Sum_sharp_less_than_u(x,y)
#define add(x,y) Add_less_than_u(x,y)
#define add2(x,y) Add_ltu_2d(x,y)
#define asss(w,z) All_Subset_Sums_sharp(w,z)
#define ass(w,z) All_Subset_Sums(w,z)

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
// ���С��u���Ӽ��� 
// ������Ϣ��
// ���룺����X
// �����X �������Ӽ� Y ��Ԫ��֮�� 
set<int> Sum_less_than_u(set<int> X, int u){
	// TODO: Please implement me;
}
// ���С��u���Ӽ���,����ʾΪ���� (Sum_Y_i, cardinality) ����ʽ 
// ������Ϣ��
// ���룺����X
// ����������ļ��ϣ���������������Ϣ��
// 1. X ���Ӽ� Y_i ��Ԫ��֮�� 
// 2. Y_i �� ���� 
set< vector< int, int> > Sum_sharp_less_than_u(set<int> X, int u){
	// TODO: Please implement me;
}
// ����һ�����ϣ�Ԫ��Ϊ��Element_i = X_i + Y_j <= u ? X_i + Y_j : u;  
set<int> Add_less_than_u(set<int> X, set<int> Y){
	// TODO: Please implement me;
	
}
// ���溯���Ķ�ά��ʽ 
set<vector<int> > Add_ltu_2d(set<vector<int> > X, set<vector<int> > Y){
	// TODO: Please implement me;
	
}
// General function 
set<vector<int> >  All_Subset_Sums_sharp(set<int> X, int upper_bound_u){
	if(X.size() == 1){
		set<vector<int> > result;
		result.insert(vector<int>(2,0));
		vector<int> temp; 
		temp.push_back(*X.begin());
		temp.push_back(1);
		result.insert(temp);
		return result; 
	}else{
		// �� T Ϊ S ������һ�� ����Ϊ n/2���Ӽ�
		set<int> T;
		set<int>::iterator it;
		int count = 0; 
		int n_2 = X.size()/2;
		for (it = X.begin(); it != X.end(); it++,count++){
    	//	cout<<*it<<" ";        // ��ʱΪ������׼�� 
    		if(count == n_2){
    			break;
			}
    		T.insert(*it);
    		X.erase(*it);
    	}
    	return add2(asss(T,u),asss(X,u));
	}
} 
set<vector<int> >  All_Subset_Sums(set<int> X, int upper_bound_u){
	int n = X.size();
	int b = sqrt(n*log(n));
	vector<set<vector<int> > > R;
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
		// ȡ���� 
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
    		set<vector<int> > temp;
    		vector<int> temp_vector;
    		temp_vector.push_back((*it_subqi)[0]*b);
    		temp_vector.push_back((*it_subqi)[1]*i);
    		temp.insert(temp_vector);
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
