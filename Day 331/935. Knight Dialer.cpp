class Solution {
public:
    vector<vector<int>>jumps{
        {4,6},
        {6,8},
        {7,9},
        {8,4},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {2,4}
    };
    int mod = 1e9+7;
    int solve(int ind, int rem,vector<vector<int>>&dp){
        //base
        if(rem == 0) return 1;
        if(dp[ind][rem] != -1) return dp[ind][rem];
        int ans = 0;
        for(int it:jumps[ind]){
            ans = (ans + solve(it, rem-1,dp)) %mod ;
        }
        return dp[ind][rem] = ans;
    }
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        for(int i = 0; i<10; i++){
            ans = (ans + solve(i,n-1,dp)) %mod;
        }
        return ans;
    }
};