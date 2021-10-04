#include<bits/stdc++.h>
using namespace std;



bool solve(int arr[], int sum, int n, int t[]){
	if (arr && !sum)
		return t[n][sum]=true;
	else if(!sizeof(arr) && sum)
		return t[n][sum]=false;
		
	if (arr[n-1] <= sum){
		return t[n][sum]= solve(arr, sum-arr[n-1], n-1, t) || solve(arr, sum, n-1, t);
	}
	else if (arr[n-1] > sum){
		return t[n][sum] = solve(arr, sum, n-1, t);
	}
}

int main(){
	int arr[]={ 3, 34, 4, 12, 5, 2 };
	int sum=9;
	int n = sizeof(arr)/sizeof(sum);
	int t[n][sum];
	
	if (solve(arr, sum, n, t) == true)
		cout<<"Sum found";
	else
		cout<<"Not found";
	return 0;
}