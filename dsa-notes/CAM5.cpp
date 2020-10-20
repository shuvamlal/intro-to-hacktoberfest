using namespace std;
 
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
 
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
 
 
int main(){
	int t;
	cin>>t;
	for(int i{0}; i<t; i++){
		unordered_map <int, vector<int> > G;
		
		int n,e;
		cin>>n;
		cin>>e;
		for(int j{0}; j<e; j++){
			int a,b;
			cin>>a>>b;
			G[a].push_back(b);
			G[b].push_back(a);
			}
			
/*		tr(G,it){
			cout<<(*it).first<<"--- ";
			tr((*it).second, ite){
				cout<<*ite<<" ";
				}
			cout<<"\n";
			}
*/			
		vector <bool> seen(n,false);
		int count{0};
		
		
		for(int v{0}; v<n; v++){
			if (!seen[v]){
				count += 1;
				
				//bfs(v);
				
				queue <int> q;
				q.push(v);
				seen[v] = true;
				
				while (!q.empty()){
					int temp = q.front();
					q.pop();
					tr(G[temp],it){
					if (!seen[*it]){
						seen[*it] = true;
						q.push(*it);
						}
					}			
				}			
			}
		}	
		cout<<count<<endl;
	}
	return 0;
}
