class Solution {
public:

    int solve(int i, int j, string &s, vector<vector<int>>& dp){
        // base case
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int turns = INT_MAX;
        for(int k = i; k<j; k++){
            turns = min(turns , solve(i,k,s,dp)+ solve(k+1,j,s,dp));
        }
        return dp[i][j] = (s[i] == s[j])? turns -1: turns ;
    }


    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};