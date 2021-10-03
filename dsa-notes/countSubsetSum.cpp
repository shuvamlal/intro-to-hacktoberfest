#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {2,3,5,6,8,11};
	int sum = 11;
	int n = sizeof(arr)/sizeof(int);
	
	int t[n+1][sum+1];
	memset(t, -1, sizeof(t));
	
	// top-down approach is as follows
	
	// base-case initialization
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if (i==0 && j != 0){
				t[i][j] = 0;
			}
			else if(j==0){
				t[i][j] = 1;
			}
		}
	}
	
	// conditions for subset sum count
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if (arr[i-1] <= j){
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	
	cout<<t[n][sum];
	
	return 0;
}