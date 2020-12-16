#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
#include <complex>

using namespace std;

#define S(x) Sum_X(x)
#define add(x,y,z) Add_less_than_u(x,y,z)
#define add2(x,y) Add_ltu_2d(x,y)
#define asss(w,z) All_Subset_Sums_sharp(w,z)
#define ass(w,z) All_Subset_Sums(w,z)
#define cp complex<double>
#define MAXN 30
#define N 30
#define fo(x,y,z) for(x = y; x<z+1; x++)

const double pie=acos(-1);
int n;
cp a[N],b[N];
int rev[N],ans[N];
char s1[N],s2[N];
void swap1(cp &a, cp &b){

}

void fft(cp *a,int n,int inv)
{
    int bit=0;
    while ((1<<bit)<n)bit++;
	int i;
    fo(i,0,n-1)
    {
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        if (i<rev[i])swap1(a[i],a[rev[i]]);//不加这条if会交换两次（就是没交换）
    }
    for (int mid=1;mid<n;mid*=2)//mid是准备合并序列的长度的二分之一
    {
    	cp temp(cos(pi/mid),inv*sin(pi/mid));//单位根，pi的系数2已经约掉了
        for (int i=0;i<n;i+=mid*2)//mid*2是准备合并序列的长度，i是合并到了哪一位
		{
            cp omega(1,0);
            for (int j=0;j<mid;j++,omega*=temp)//只扫左半部分，得到右半部分的答案
            {
                cp x=a[i+j],y=omega*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;//这个就是蝴蝶变换什么的
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
