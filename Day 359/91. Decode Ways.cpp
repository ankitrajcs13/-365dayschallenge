class Solution {
public:
    int solve(int i, string s,vector<int>&dp){
        int n = s.length();
        if(i> n || s[i] == '0') return 0;
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        int t1 = solve(i+1,s,dp);
        int t2 = 0;
        if(s[i] == '1' || (s[i] == '2' && s[i+1]<= '6')){
            t2 = solve(i+2,s,dp);
        }
        return dp[i] = t1+t2;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n+2,0);
        dp[n] = 1, dp[n+1] = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == '0') dp[i] = 0;
            else{
                dp[i] += dp[i+1];
                if(s[i] == '1' || (s[i] == '2' && s[i+1]<= '6')){
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
};