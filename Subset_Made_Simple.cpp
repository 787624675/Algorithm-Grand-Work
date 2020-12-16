#include <iostream>
#include <set>
using namespace std;
// 定义后需要用到的一些基本的函数 
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
