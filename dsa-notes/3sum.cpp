class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        if (n <= 2)
            return ans;
        
        int i=0;
        while (i < n-2){
            
            int left = i+1;
            int right = n-1;
            
            
            while (left < right){
                if (nums[i] + nums[left] + nums[right] < 0){
                    left += 1;
                }
                else if (nums[i] + nums[left] + nums[right] > 0){
                    right -= 1;
                }
                else{
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);
                    int tmp = nums[left];
                    while (nums[left] == tmp && left < right) left++;
                    tmp = nums[right];
                    while (nums[right] == tmp && right > left) right--;
                }
            }
            int tmp = nums[i];
            while (nums[i] == tmp && i< n-2) i++;
        }
        return ans;
    }
};
