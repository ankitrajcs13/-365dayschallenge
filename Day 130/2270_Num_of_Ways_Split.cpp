class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long pref[n];
        long long postf[n];
        pref[0]=nums[0];
        postf[n-1]=nums[n-1];
        int c=0;
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+nums[i];
        for(int i=n-2;i>=0;i--)
            postf[i]=postf[i+1]+nums[i];
        for(int i=0;i<n-1;i++)
            if(pref[i]>=postf[i+1]) 
                c++;
        return c;
    }
};