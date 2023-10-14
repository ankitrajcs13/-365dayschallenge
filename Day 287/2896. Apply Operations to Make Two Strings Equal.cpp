class Solution {
public:
    int solve(int l, int r, vector<vector<int>>&dp,vector<int>&d,int x ){
        // base case 
        int n = d.size();
        if(l>=n) return 0;
        if(r < 0) return 0;
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int a = d[l+1] - d[l] + solve(l+2,r,dp,d,x);
        int b = d[r] - d[r-1] + solve(l,r-2,dp,d,x);
        int c = x + solve(l+1,r-1,dp,d,x);

        return dp[l][r] = min(a,min(b,c));
    }
    int minOperations(string s1, string s2, int x) {
        vector<int>d;
        int n = s1.size();
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]) d.push_back(i);
        }

        // if it's odd
        if(d.size() % 2 != 0) return -1;
        if(d.size() == 0) return 0;

        vector<vector<int>>dp(501,vector<int>(501,-1));
        return solve(0,d.size()-1,dp,d,x);
    }
};