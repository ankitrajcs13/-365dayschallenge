class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        int tmp = 0;
        for(int i = 0; i<nums.size(); i++){
            if( (maxi & nums[i]) == maxi) tmp++;
            else tmp = 0;
            cnt = max(cnt,tmp);
        }
        return cnt;
    }
};



// TC - O(N)