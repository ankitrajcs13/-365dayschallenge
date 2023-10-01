class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return 0;
        
        vector<long long> ankipre(n), suf(n);
        
        ankipre[0] = nums[0];
        for(int i = 1; i<n; i++){
            ankipre[i] = max(ankipre[i-1], (long long)nums[i]);
        }
        suf[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            suf[i] = max(suf[i+1] , (long long)nums[i]);
        }
        long long ankiRes = 0;
        for(int j = 1; j<n-1; j++){
            long long tmp = (ankipre[j-1] - nums[j]) * suf[j+1];
            ankiRes = max(ankiRes,tmp);
        }
        if(ankiRes < 0) return 0;
        return ankiRes;
    }
};