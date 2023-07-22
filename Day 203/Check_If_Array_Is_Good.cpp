class Solution {
public:
    bool isGood(vector<int>& nums) {
        int ankin = nums.size();
        if(ankin <=1) return false;
        sort(nums.begin(), nums.end());
        
        if(nums[ankin-1] == nums[ankin-2] && nums[ankin-1] == ankin-1) return true;
        else return false;
    }
};