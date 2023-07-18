class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0,j = 0, res = 0;
        while(i <nums.size()){
            if(2* k <  nums[i] - nums[j]) j++;
            else res = max(res, i-j+1);
            i++;
        }
        return res;
    }
};