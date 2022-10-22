class Solution {
    int lis(vector<int>& nums){
        int n = nums.size();
        int dp[n+5];
        for(int i=0;i<=n;i++)
            dp[i]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
         // for(int i=0;i<=n;i++)
         //    cout<<dp[i]<<" ";
        
        return *max_element(dp,dp+n);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return lis(nums);
    }
};
