#include <iostream>
#include <cmath>
using namespace std;

void tug_of_war(int arr[],int n, int tSum, int pos, int out[], int count1,
                int sum1, int fOut[], int &min_diff){
    if(count1==n/2){
        int diff=abs(tSum-2*sum1);
        if (diff<min_diff){
            min_diff=diff;
            for (int i=0;i<n;i++){
                fOut[i]=out[i];
            }
        }
        return;
    }
    if (pos>=n) return;
    ///dont consider current element in the left array
    tug_of_war(arr,n,tSum,pos+1,out,count1,sum1,fOut,min_diff);
    ///Consider the current element in left
    out[pos]=1;
    tug_of_war(arr,n,tSum,pos+1,out,count1+1,sum1+arr[pos],fOut,min_diff);
    out[pos]=0;
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    int out[100]={}, fOut[100]={};
    int min_diff=INT_MAX;
    int tsum=0;
    for (int i=0;i<n;i++) tsum+=arr[i];

    tug_of_war(arr,n,tsum,0,out,0,0,fOut,min_diff);

    for (int i=0;i<n;i++){
        if (fOut[i]==1) cout<<arr[i]<<", ";
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        if (fOut[i]==0) cout<<arr[i]<<", ";
    }
    cout<<endl<<min_diff;
}
