class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        // edge case
        if(nums[0] == 1 && nums[n-1] == n) return 0;

        int ans = 0;
        int fpos = -1, lpos = -1;

        for(int i = 0; i<n; i++){
            if(nums[i] == 1) fpos = i;
            if(nums[i] == n) lpos = i;
        }

        if(fpos > lpos) 
            return fpos + n -1-lpos-1;
        return fpos+n-1-lpos;
    }
};