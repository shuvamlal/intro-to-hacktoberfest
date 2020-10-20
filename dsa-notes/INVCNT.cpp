#include <bits/stdc++.h>

using namespace std;

#define ll long long int


struct FenwickTree{
	
	ll n;
	vector<ll> bit;
	
	FenwickTree(ll n){
		this->n = n+1;
		bit.assign(this->n, 0);
		}
		
	void add(ll idx, ll val){
		for(idx=idx+1; idx<n; idx += idx & -idx)
			bit[idx] += val;
		}
	
	ll sum(ll idx){
		ll res = 0;
		for(idx=idx+1; idx>0; idx -= idx & -idx)
			res += bit[idx];
		return res;
		}
	
	ll sum(ll l, ll r){
		return sum(r)-sum(l-1);
		}
		
	};

int main(){
	
	ll t;
	cin>>t;
	
	
	
	while (t--){
		ll n;
		cin>>n;
		ll arr[n];
		ll max = -1;
		
		for(ll i=0; i<n; i++){
			cin>>arr[i];
			max = (arr[i]>max)?arr[i]:max;
			}
		
		//cout<<"input over"<<endl;
		
		
		FenwickTree tree(max);
		
		ll count = 0;
		for(ll i=n-1; i>=0; i--){
			count += tree.sum(arr[i]-1);
			tree.add(arr[i],1);
			}
		cout<<count<<endl;
		
		}
	
	return 0;
	}
