class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        // using binary search
        int st = 0;
        int end = nums.size()-1;
        int mid = st + (end-st)/2;
        while(st <= end){
            if(nums[mid] == target){
                break;
            }
            else if(nums[mid] < target)
                st = mid + 1;
            else if ( st == end && target > nums[mid]){
                mid++;
                break;
            }
            else{
                end = mid-1;
            }
            mid = st + (end - st)/2;
        }
        return mid;
    }
};