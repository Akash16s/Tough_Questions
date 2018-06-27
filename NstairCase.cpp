// Nstairs
/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 ,2 stair or 3 stairs at a time. Count the number of ways, the person can reach the top.

stairs.
*/
#include <iostream>
using namespace std;


int ways(int n){
	// Base case
	if(n==0){
		return 1;
	}

	if(n<0){
		return 0;
	}

	// Recursive case
	int ans=ways(n-1)+ways(n-2)+ways(n-3);
	return ans;

}


int main(){

	int n;
	cin>>n;

	cout<<ways(n);


	return 0;
}
