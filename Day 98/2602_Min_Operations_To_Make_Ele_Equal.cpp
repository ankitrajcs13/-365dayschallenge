class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n+1);
        // calculate the prefix sum
        for(int i = 0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + (long long)nums[i];
        }

        for (int& x : queries) {
           int li = lower_bound(nums.begin(), nums.end(),x) - nums.begin();
           res.push_back(1LL * x * (2 * li - n) + prefix[n] - 2 * prefix[li]);
        }
        return res;

    }
};