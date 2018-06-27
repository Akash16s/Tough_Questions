// substrings using recurssion 
#include<iostream>
using namespace std;
void Subsequence(char *input,int i,char *output,int j){
	//base case
	if(input[i]=='\0'){
		output[j]='\0';
		cout<<output<<endl;
		return ;
	}
	//first time
	output[j]=input[i];
	Subsequence(input,i+1,output,j+1);
   //second time
   Subsequence(input,i+1,output,j);
}
int main(){
	char a[]="abc";
	char output[100];
	Subsequence(a,0,output,0);
	
	
	return 0;
}
