class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > maxi) maxi = nums[i];
            if(nums[i] < mini) mini = nums[i];
        }


        int res = ( maxi-k ) - (mini + k);
        if(res > 0) return res;
        return 0;



    }
};