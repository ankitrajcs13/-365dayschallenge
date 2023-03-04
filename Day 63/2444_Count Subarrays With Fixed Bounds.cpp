class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int miniK = -1;
        int maxiK = -1;
        int lstInv = -1;
        long long cnt = 0;

        for(int i = 0; i<nums.size(); i++){
            // check for the range bw mink and maxk
            if(nums[i] >= minK && nums[i] <= maxK){
                // update miniK
                if(nums[i] == minK) miniK = i;
                else miniK = miniK;

                // update maxiK
                if(nums[i] == maxK) maxiK = i;
                else maxiK = maxiK;

                cnt+= max (0, min(miniK,maxiK)-lstInv);
            }
            else{
                // update the lastInvalid index to change the starting pos of array
                lstInv = i;
                // now reset the miniK and maxiK as we have to start from zero again
                miniK = -1;
                maxiK = -1;
            }
        }
        return cnt;

    }
};