class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> preSum(n,0);
        vector<long long> res(n,0);
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            maxi = max(maxi,nums[i]);
            preSum[i] = nums[i] + maxi;
        }
        res[0] = preSum[0];
        for(int i = 1; i<preSum.size(); i++){
            res[i] = preSum[i] + res[i-1];
        }
        return res;
    }
};