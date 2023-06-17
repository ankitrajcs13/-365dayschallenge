class Solution {
public:
    int solve(int idx, int prev, vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp) {
        //Base case
        if(idx == arr1.size()) {
            return 0;
        }
        if(dp.find({idx, prev}) != dp.end()) {
            return dp[{idx, prev}];
        }
        int replace = 1e9, not_replace = 1e9;
        int i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(i < arr2.size()) {
            replace = 1 + solve(idx + 1, arr2[i], arr1, arr2, dp);            
        }
        if(arr1[idx] > prev) {
            not_replace = solve(idx + 1, arr1[idx], arr1, arr2, dp);
        }
        return dp[{idx, prev}] = min(replace, not_replace);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        map<pair<int,int>,int> dp;
        sort(arr2.begin(), arr2.end());
        int res = solve(0,-1,arr1,arr2,dp);
        if(res < 1e9) return res;
        return -1;
    }
};