class Solution {
public:

    int mdiff(int left, int right, vector<int>&nums){
        if(left == right) return nums[left];

        int dleft = nums[left]- mdiff(left+1,right,nums);
        int dright = nums[right]- mdiff(left,right-1,nums);

        return max(dleft,dright);
    }

    bool PredictTheWinner(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        return mdiff(left,right,nums)>=0;
    }
};