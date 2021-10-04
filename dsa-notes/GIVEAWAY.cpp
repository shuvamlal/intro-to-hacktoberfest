#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	
	vector<int> arr(n);
	int len = (int)sqrt(n+.0)+1;
	
	vector<int> brr[len];
	
	
	
	for(int i=0; i<n; i++){
		cin>>arr[i];	
		brr[ i/len ].push_back( arr[i] );
		}
	
	for(int i=0; i<len; i++)
		sort(brr[i].begin(), brr[i].end());
		
	int q;
	cin>>q;
	
	while(q){		
		int type;
		cin>>type;
		
		if (type==0){
			
			int l,r,c;
			cin>>l>>r>>c;
			
			l -= 1;
			r -= 1;
			
			int ans = 0;
			
			int c_l = l/len;
			int c_r = r/len;
			
			if (c_l == c_r){
				for(int i=l; i<=r; i++)
					if (arr[i] >= c)
						ans +=  1;
				}
			else{
				
				int end = (c_l+1)*len-1;
				
				for(int i=l; i<=end; i++){
					if (arr[i] >= c)
						ans += 1;
					}
					
				for(int i=c_l+1; i<=c_r-1; i++){
					ans += brr[i].end() - lower_bound(brr[i].begin(), brr[i].end(), c);
					}
					
				for(int i=c_r*len; i<=r; i++){
					if (arr[i] >= c)
						ans += 1;
					}
				
				}
			cout<<ans<<endl;
			}
		else{
			int a,b;
			cin>>a>>b;
			a -= 1;
			
			int pe = arr[a];
			int bn = a/len;
			
			int i = lower_bound(brr[bn].begin(), brr[bn].end(), pe) - brr[bn].begin();
			
			brr[bn][i] = b;
			arr[a] = b;
			
			sort(brr[bn].begin(), brr[bn].end());
			}
			
		q -= 1;
		}
		
	return 0;
	}
