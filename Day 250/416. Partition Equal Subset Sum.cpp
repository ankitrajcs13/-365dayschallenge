class Solution {
public:
    bool solve(vector<int>& nums, int target){
        vector<bool>prev(target+1,0), curr(target+1,0);
        if(nums[0] <= target) prev[0] = true;
        if(nums[0] <= target) prev[nums[0]] = true;

        for(int i = 1; i<nums.size();i++){
            for(int j = 1; j<=target; j++){
                bool nt = prev[j];
                bool t = false;
                if(j >= nums[i]) t = prev[j - nums[i]];
                curr[j] = nt||t;
            }
            prev = curr;
        }
        return prev[target];

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int it:nums) sum+=it;
        if(sum%2 != 0)return false;
        int target = sum/2;
        int n = nums.size();
        return solve(nums,target);
    }
};