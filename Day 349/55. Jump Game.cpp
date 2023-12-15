class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cnreach = 0;
        for(int i = 0; i<nums.size(); i++){
            if(cnreach < i) return false;

            cnreach = max(cnreach, i + nums[i]);
        }
        return true;
    }
};