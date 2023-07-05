class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zCnt = 0, logWin = 0;
        int s = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0) zCnt++;
            // using the sliding window approach
            while(zCnt >1){
                if(nums[s] == 0) zCnt--;
                s++;
            }
            logWin = max(logWin,i-s);
        }
        return logWin;
    }
};