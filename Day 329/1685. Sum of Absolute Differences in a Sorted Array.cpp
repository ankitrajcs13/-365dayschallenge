class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefSum(n);
        vector<int>res;
        int pref = 0;
        int totsum = accumulate(begin(nums), end(nums),0);
        for(int i = 0; i<n; i++){
            int lsum = pref;
            int rsum =  totsum - pref - nums[i];
            int ans = ( nums[i] * i) - lsum + rsum - (nums[i] * (n-i-1));
            res.push_back(ans);
            pref += nums[i];
        }
        return res;
    }
};