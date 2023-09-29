class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        bool isInc = false;;
        bool isDec = false;
        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]) isInc = true;
            if(nums[i] > nums[i+1]) isDec = true;
        }

        if(isInc && isDec) return false;
        return true;
              
    }
};