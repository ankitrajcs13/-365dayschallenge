class Solution {
public:
    int solve(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;

        for(int i =1;i<nums.size(); i++){
            int take = nums[i] + prev2;
            int ntake = 0 + prev;

            int curr = max(take,ntake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        vector<int> tmp1,tmp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i = 0;i<n; i++){
            if(i!=0) tmp1.push_back(nums[i]);
            if(i!=n-1) tmp2.push_back(nums[i]);
        }

        return max(solve(tmp1), solve(tmp2));
    }
};