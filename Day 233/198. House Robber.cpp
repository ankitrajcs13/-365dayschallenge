class Solution {
public:
    int rob(vector<int>& nums) {
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
};