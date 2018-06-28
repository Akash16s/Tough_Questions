//Sudoko recursion retry 
#include<iostream>
using namespace std;
bool isSafeToPlace(int mat[][9],int i,int j,int n,int number){
	for(int k=0;k<n;k++){
		if(mat[i][k]==number||mat[k][j]==number){
			return false;
		}
		i=(i/n)*i;
		j=(j/n)*j;
	}
	
}
bool SolveSudoko(int mat[][9],int i,int j,int n ){
	//base case
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
			      cout<<mat[i][j]<<" ";
					cout<<endl;
					}
       return true;
		}
	//other cases
	if(j==n){
		return SolveSudoko(mat,i+1,0,n);
	}	
	if(mat[i][j]!=0){
		return SolveSudoko(mat,i,j+1,n);
	}
		
	//recursive case
	for(int number=1;number<=n;number++){
		if(isSafeToPlace(mat,i,j,n,number)){
			mat[i][j]=number;
			bool kyaBakiRakhPaye=SolveSudoko(mat,i,j+1,n);
			if(kyaBakiRakhPaye){
				return true;
			}
			mat[i][j]=0;
		}
	}
	return false;
	
}
int main(){
	int mat[9][9] = {{5,3,0,0,7,0,0,0,0}, 
	                 {6,0,0,1,9,5,0,0,0}, 
					 {0,9,8,0,0,0,0,6,0}, 
					 {8,0,0,0,6,0,0,0,3}, 
					 {4,0,0,8,0,3,0,0,1}, 
					 {7,0,0,0,2,0,0,0,6}, 
					 {0,6,0,0,0,0,2,8,0}, 
					 {0,0,0,4,1,9,0,0,5}, 
					 {0,0,0,0,8,0,0,7,9}}; 
					 
	SolveSudoko(mat,0,0,9);				 
	
	return 0;
}
