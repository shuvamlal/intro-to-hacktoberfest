#include <bits/stdc++.h>

#define ll long long int


using namespace std;


ll mod(ll a){
	if (a>=0){ return a; }
	return (a*(-1));
	}


bool pf(ll a){
	
	
	ll cnt = 0;
	while (a%2==0 && a!=0){
		a = a/2;
		cnt += 1;
		
		if (cnt >= 2)
			break;
		}
		
	if (cnt==1)
		return true;
	else
		return false;
	}

int main(){
	int t;
	cin>>t;
	
	
	while (t--){
		ll n;
		cin>>n;
		
		ll arr[n+1];
		for(ll i=1; i<=n; i++){
			cin>>arr[i];
			}
			
		ll last=0,slast=0;
		ll ng=0;
		for(ll i=1; i<=n; i++){
			
			if (arr[i]&1){
				ng += last-slast;
				}
			else{
				bool flag = pf( mod(arr[i]) );
				if (flag){
					slast = last;
					last = i;
					ng += last-slast;
					}
				else{
					slast = last = i;
					}
				}
			}			
		ll ans = (n*(n+1))/2 - ng;
		cout<<ans<<endl;
		}    
	return 0;
	}
