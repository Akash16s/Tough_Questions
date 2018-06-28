//chess elephant (seems wrong) 
//the ques is that in how many ways a elephant can travel on board of chess of n*m dimension
#include<iostream>
using namespace std;
int moves(int n,int m){
	if(n==0&&m==0){
		return 1;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
	sum=sum+moves(n-i,m);
	}
	for(int j=1;j<=m;j++){
	 sum=sum+moves(n,m-j);
	}
	return sum;
}
int main(){
	cout<<moves(2,2)<<endl;
	return 0;
}
