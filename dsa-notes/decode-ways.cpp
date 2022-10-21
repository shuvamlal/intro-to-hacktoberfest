class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> dp(n+1,0);
        if(s[0]=='0'){
            dp[0]=0;
        }
        else 
            dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0' and s[i-1]=='0'){
                dp[i]=0;
            }
            if(s[i]=='0' and s[i-1]!='0'){
                string temp ;
                temp.push_back(s[i-1]);
                temp.push_back(s[i]);
                if(temp<"27"){
                    if(i-2>=0){
                        dp[i] += dp[i-2];
                    } else {
                        dp[i] += 1; 
                    } 
                }
                else {
                    dp[i]=0;
                }
            }
            if(s[i]!='0' and s[i-1]=='0'){
                dp[i]+=dp[i-1];
            }
            if(s[i]!='0' and s[i-1]!='0'){
                string temp ;
                temp.push_back(s[i-1]);
                temp.push_back(s[i]);
                if(temp<"27"){
                        dp[i] = dp[i-1]+1;
                    if(i-2>=0){
                        dp[i] = dp[i-1]+dp[i-2];
                        if(dp[i-2]==0)
                            dp[i]=0;
                    }
                } else {
                    dp[i] += dp[i-1];
                }
            }
        }
        for(auto x:dp)
            cout<<x<<" ";
        return dp[n-1];
    }
};
