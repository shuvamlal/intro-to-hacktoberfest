#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int A[n],B[n],C[n],D[n];
	
	for(int i=0; i<n; i++){
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		}
		
		
	vector<int> arr2;
			
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			arr2.push_back( C[i]+D[j] );
			}
		}
		
	sort(arr2.begin(), arr2.end());
		
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int tempsum = -(A[i]+B[j]);
			ans += upper_bound(arr2.begin(),arr2.end(),tempsum) - lower_bound(arr2.begin(),arr2.end(),tempsum);
			}
		}
 
	cout<<ans<<endl;
	
	return 0;
	}
