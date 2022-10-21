class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return ;
        int idx=-1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                idx = i;
                break;
            }
        }
        if(idx<0)
        {
            reverse(nums.begin(), nums.end());
            return ;
        }
        for(int i=n-1; i>=idx; i--) {
            if(nums[i]>nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+idx+1, nums.end());
        
        
    }
};
/*
1,2,3
1,3,2
2,1,3
2,3,1
3,1,2
3,2,1

1,2,3

1,2,3,4
1,2,4,3
1,3,2,4
1,3,4,2
1,4,2,3


*/
