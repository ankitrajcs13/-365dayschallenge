class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // bs
        int lo = 0, hi = nums.size()-1;

        while(lo<=hi){

            // to avoid duplicates
            while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
            while (lo < hi && nums[hi] == nums[hi - 1]) --hi;

            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target) return true;

            // if left is sorted
            if(nums[lo] <= nums[mid] ){
                if(nums[lo] <= target && target < nums[mid])
                    hi = mid-1;
                else lo = mid+1;
            }
            // right is sorted
            else{
                if(nums[mid] < target && target <= nums[hi]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};