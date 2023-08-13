class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(dp,nums,0,nums.size());
    }
    bool solve(vector<int> &dp, vector<int>&nums, int i, int j){
        if(i>=j) return true;
        // memorization
        if(dp[i] !=-1) return dp[i];
        // first case for 2 elements
        if(i+1 < j && nums[i] == nums[i+1]){
            dp[i] = solve(dp,nums,i+2,j);
            if(dp[i]) return true;
        }

        if(i+2 < j && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
            dp[i] = solve(dp,nums,i+3,j);
            if(dp[i]) return true;
        }

        if(i+2 < j && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1){
            dp[i] = solve(dp,nums,i+3,j);
            if(dp[i]) return true;
        }
        return dp[i] = false;
        
    }
};