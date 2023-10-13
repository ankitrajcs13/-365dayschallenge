class Solution {
public:
    // tabulation : Bottom UP
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);

        for(int i = 0; i<n; i++){
            // base case
            if(i<2) dp[i] = cost[i];
            else dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
            
        }
        return min(dp[n-1], dp[n-2]);
    }
};