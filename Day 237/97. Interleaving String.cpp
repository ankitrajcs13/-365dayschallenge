class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, vector<vector<int>>& dp){
        // base case
        if(i+j==s3.length()) return 1;
        bool res = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i<s1.length() && s1[i]==s3[i+j]){
            res = (res | solve(s1,s2,s3,i+1,j,dp));
        }
        if(j<s2.length() && s2[j] == s3[i+j]){
            res = (res | solve(s1,s2,s3,i,j+1,dp));
        }
        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        //base case
        int n1 = s1.length(), n2= s2.length(), n3 = s3.length();
        if(n1+n2 != n3) return 0;

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));

        return solve(s1,s2,s3,0,0,dp);
        
    }
};