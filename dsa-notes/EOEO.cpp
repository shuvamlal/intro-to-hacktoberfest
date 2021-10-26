#include <bits/stdc++.h>

using namespace std;


#define ll long long unsigned int 


ll bpow(ll a, ll b){
	ll res = 1;
	
	while (b){
		
		if (b&1)
			b -= 1, res = res*a;
		
		b = b/2;
		a = a*a;
		}
		
	return res;
	}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll t;
	cin>>t;
	
	ll ts,ot;
	while (t--){
		cin>>ts;
		ot = ts;
		
		ll cnt = 0;
		while (ts%2==0){
			ts = ts/2;
			cnt += 1;
			}
		//cout<<"cnt is "<<cnt<<endl;

		ll k = cnt+1;
		ll res=0;
		ts = ts+1;
		while (true){
			ll lim = bpow(2,k);
			if (lim > ot)
				break;
			
			//cout<<"try with k= "<<k<<endl;
			
			ll a = 1;
			ll b = ts;
			ll mid,ans=0;
			while ( a <= b){
				mid = (a+b)/2;
				if (mid*lim <= ot){
					a = mid + 1;
					}
				else{
					ans = mid;
					b = mid - 1;
					}
				}
			//cout<<"first invalid is "<<ans<<endl;
			res += (ans)/2;
			k += 1;
			ts = ts/2 + 1;
			}
		cout<<res<<endl;
		
		}
	return 0;
	}
