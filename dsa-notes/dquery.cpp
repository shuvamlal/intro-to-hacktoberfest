#include <bits/stdc++.h>

using namespace std;
const int BLOCK_SIZE = 150;
int arr[30010];
unordered_set<int> ds1;
unordered_map<int,int> ds2;

struct Query{
	int l,r,idx;
	
	Query(int a, int b, int i) : l(a), r(b), idx(i) {}
	
	bool operator < (Query& other) const {
		/* return make_pair(l / BLOCK_SIZE, r) <
               make_pair(other.l / BLOCK_SIZE, other.r);  */
               
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
        		return make_pair(l, r) < make_pair(other.l, other.r);		
		return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
		}
	
	};

vector<Query> query;


int get_answer(){
	return (int)ds1.size();
	}
	
void add(int idx){
	ds2[arr[idx]] += 1;
	if (ds2[arr[idx]]==1)
		ds1.insert(arr[idx]);
	}
	
void remove(int idx){
	ds2[arr[idx]] -= 1;
	if (ds2.find(arr[idx]) != ds2.end() && ds2[arr[idx]]==0)
		ds1.erase(arr[idx]);
	}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	//BLOCK_SIZE = sqrt(n);
	
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	int q;
	cin>>q;
	
	int answer[q];
	
	int l,r;
	for(int i=0; i<q; i++)
		cin>>l>>r, query.push_back( Query(l-1,r-1,i) );
		
	sort(query.begin(), query.end());
	
	int cur_l=0,cur_r=-1;
	
	for(auto& q : query){
		
		while (q.l > cur_l){
			remove(cur_l);
			cur_l += 1;
			}
		while (q.l < cur_l){
			cur_l -= 1;
			add(cur_l);
			}
			
		while (q.r > cur_r){
			cur_r += 1;
			add(cur_r);
			}
			
		while (q.r < cur_r){
			remove(cur_r);
			cur_r -= 1;
			}
		answer[q.idx] = get_answer();
		//cout<<"query "<<q.l<<" "<<q.r<<" ans "<<answer[q.idx]<<endl;
		}
		
	for(int i=0; i<q; i++){
		cout<<answer[i]<<endl;
		}
	
	return 0;
	}
