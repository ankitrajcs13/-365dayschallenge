class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        vector<int> prev(n,-1), suff(n,-1);
        for(int i = 1; i<n-1; i++){
            prev[i] = mini;
            mini = min(mini, nums[i]);
        }

        mini = nums[n-1];
        for(int i = n-2; i>0; i--){
            suff[i] = mini;
            mini = min(mini,nums[i]);
        }
        mini = INT_MAX;
        for(int i = 1; i<n-1; i++){
            if(nums[i] > prev[i] && nums[i] > suff[i]) mini = min(mini, nums[i] + prev[i] + suff[i]);
        }
        return mini == INT_MAX? -1: mini;
    }
};