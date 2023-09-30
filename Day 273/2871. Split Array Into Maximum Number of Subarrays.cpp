class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int AnkiFl = INT_MAX;
        for(auto it: nums){
            AnkiFl  = AnkiFl & it;
        }
        if(AnkiFl != 0) return 1;
        int mxi = INT_MAX, MS = 0;
        for(auto it:nums){
            mxi &=it;
            // creating next subarray mxi and FL both becomes zero here
            // According to first ques
            if(mxi == AnkiFl){
                MS++;
                mxi = INT_MAX;
            }
        }
        return MS;
    }
};