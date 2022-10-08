
map<int,int> mp;

class Comparator{
    public:
    bool operator() (int a, int b) {
        return mp[a] < mp[b] ;
    }  
};

    
class Solution {
public:
    // function<bool(int&,int&)> comp = [](int &a, int &b) { return mp[a] < mp[b]; };
    // priority_queue<int, vector<int>, function<bool(int&, int&)> > q(comp);
    
    priority_queue<int, vector<int>, Comparator> q;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        mp.clear();
        vector<int> ans;
        
        for(auto& each : nums)
            mp[each] += 1;
        
        set<int> uniques;
        for(auto& each : nums)
            uniques.insert(each);
        
        for(auto each : uniques){
            q.push(each);
        }
        
        while (k--){
            ans.push_back(q.top());
            q.pop();
        }
        
        
        return ans;
    }
};
