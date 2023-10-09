class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        int f = -1, l = -1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                f = mid, l = mid;
                while(f>0 && nums[f-1] == target) f--;
                while(l < nums.size()-1 && nums[l+1] == target) l++;
                break;
            }
            else if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }
        return {f,l};
    }
};