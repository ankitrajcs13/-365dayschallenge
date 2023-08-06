class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int ankiN = nums.size();
        if(ankiN < 3) return true;
        for(int i = 0; i<ankiN-1; i++){
            if(nums[i] + nums[i+1] >= m)return true;
        }
        return false;
    }
};