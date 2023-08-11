class Solution {
public:
    int solve(int ind,int tar,vector<int>& coins,vector<vector<int>> &dp){
            // base case
        if(ind == 0) return (tar % coins[0] == 0);

        if(dp[ind][tar] != -1) return dp[ind][tar];

        int t = 0,nt = 0;
        nt = solve(ind-1,tar,coins,dp);
        if(coins[ind] <= tar) t = solve(ind,tar-coins[ind], coins,dp);
        return dp[ind][tar] = t+nt;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};