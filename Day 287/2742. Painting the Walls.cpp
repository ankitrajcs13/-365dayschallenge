class Solution {
public:
    int solve(int ind, int w,vector<int>& cost, vector<int>& time,vector<vector<int>>&dp ){
        // base case

        if(w < 1) return 0;
        if(ind == cost.size()) return 1e9;
        if(dp[ind][w] != -1) return dp[ind][w];
        int take = cost[ind] + solve(ind+1, w -1-time[ind],cost,time,dp);
        int nottake = solve(ind+1,w,cost,time,dp);
        return dp[ind][w] = min(take,nottake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size(), m = time.size();
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return solve(0,n,cost,time,dp);
    }
};