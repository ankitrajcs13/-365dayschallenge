class Solution {
public:
    int MOD = 1e9+7;
    int solve(int idx, int steps,int arrLen,vector<vector<long long int>>&dp){

        if( idx < 0 || idx >= arrLen || steps < 0) return 0;
        if(steps == 0 && idx == 0) return 1;
        if(dp[steps][idx] != -1) return dp[steps][idx];
        // left
        
        long long int left = solve( idx - 1,steps - 1, arrLen, dp) % MOD;
        long long int right = solve(idx + 1,steps - 1, arrLen,  dp) % MOD;
        long long int stay = solve(idx, steps - 1, arrLen, dp) % MOD;

        return dp[steps][idx] = (left + stay + right) % MOD;
    }
    int numWays(int steps, int arrLen) {
        if(arrLen > steps) arrLen = steps;
        vector<vector<long long int>> dp(steps + 1, vector<long long int>(arrLen, -1));
        return solve(0,steps,arrLen,dp);
    }
};