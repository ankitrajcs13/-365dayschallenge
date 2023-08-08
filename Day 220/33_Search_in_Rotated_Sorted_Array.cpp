    class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we can use binary search
        int l = 0, h = nums.size()-1;

        while(l<=h){
            int mid = l + (h-l)/2;

            if(nums[mid] == target) return mid;

            //if left is sorted
            if(nums[l] <= nums[mid]){
                // now check if it is between low and mid
                if(nums[l] <= target && target <= nums[mid]){
                    // then move to left part
                    h = mid-1;
                }
                else l = mid+1;
            }
            // it means right is sorted
            else{
                // now check if it is between mid and high
                if(nums[mid] <= target && target <= nums[h]){
                    // then move to right part
                    l = mid+1;
                }
                else h = mid-1;
            }
        }
        return -1;
    }
};