class Solution {
public:
    bool isPerfect(int n){
        long long sr = sqrt(n);
        return (sr * sr == n);
    }
    int solve(int ind, int t, vector<int>&cn,vector<vector<int>>&dp){
        if(ind == 0){
            if(t % cn[ind] == 0) return t/cn[ind];
            else return 1e9;
        }
        if(dp[ind][t] != -1) return dp[ind][t];
        int nt = 0 + solve(ind-1,t,cn,dp);
        int ta = 1e9;
        if(cn[ind] <= t){
            ta = 1 + solve(ind, t- cn[ind], cn, dp); 
        }

        return dp[ind][t] = min(nt,ta);
    }
    int numSquares(int n) {
        vector<int>cn;
        for(int i = 1; i<=n; i++){
            if(isPerfect(i)) cn.push_back(i);
        }
        int sz = cn.size();
        vector<vector<int>>dp(sz,vector<int>(n+1,-1));
        return solve(sz-1,n,cn,dp);
        //return cn[1];
        
    }
};