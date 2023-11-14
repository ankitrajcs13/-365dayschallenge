class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2,vector<vector<int>>&dp ){
        if(i<0 && j < 0) return true;
        if(i<0 && j>=0) return false;
        if(j < 0 && i >=0){
            for(int it = 0; it<=i; it++){
                if(s1[it] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j] || s1[i] == '?') return dp[i][j] = solve(i-1,j-1,s1,s2,dp);

        if(s1[i] == '*'){
            return dp[i][j] = solve(i-1,j,s1,s2,dp) || solve(i,j-1,s1,s2,dp);
        }
        return dp[i][j] =  false;
    }
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return solve(n-1,m-1,p,s,dp);
    }
};