class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int s = abs(nums[i] - nums[j]);
                // it's a strong pair
                if(s <= min(nums[i], nums[j])){
                    int x = nums[i] ^ nums[j];
                    res = max(res,x);
                }
            }
        }
        return res;
    }
};