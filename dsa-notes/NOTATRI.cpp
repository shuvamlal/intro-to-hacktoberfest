#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> arr;
 
int main(){
	
	while (true){
		
		arr.clear();
		
		int n;
		cin>>n;
		
		if (n==0){
			break;
			}
	
		int temp;
		for(int i=0; i<n; i++){
			cin>>temp;
			arr.push_back(temp);
			}
			
		sort(arr.begin(),arr.end());
			
		long long int ans = 0;
		for(int i=0; i<n-2; i++){
			for(int j=i+1; j<n-1; j++){
				int c = arr[i]+arr[j];
				int index = upper_bound(arr.begin()+(j+1), arr.end(), c) - arr.begin();
					
				ans += n-index ;
				}
			}
			
		cout<<ans<<endl;
		}
	
	return 0;
	}
