#include <bits/stdc++.h>
using namespace std;

int t[5][8];

int knapsack(int wt[], int val[], int w, int n){
	// cout<<"A"<<endl;
	if (n==0 || w==0)
		return 0;
	if (t[n][w]!=-1){
		return t[n][w];
	}
	
	if(wt[n-1] <= w){
		return t[n][w] = max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1), 
		    knapsack(wt, val, w, n-1));
	}
	else{
		return t[n][w] = knapsack(wt, val, w, n-1);
	}
	
	// return t[3][3];
}

int main(){
	
	int wt[4]={1,3,4,5};
	int val[4]={1,4,5,7};
	int w=7;
	memset(t, -1, sizeof(t));
	for(int i=0;i<5;i++){
		for(int j=0;j<8;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	// cout<<t[3][3]<<endl;
	int profit = knapsack(wt, val, w, 4);
	cout<<profit<<"\n";
	
	for(int i=0;i<5;i++){
		for(int j=0;j<8;j++){
			cout<<t[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
	
}