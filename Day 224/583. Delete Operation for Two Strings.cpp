class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1,string &s2,int i, int j){
        if(i>= s1.length()&& j >= s2.length()) return 0;
        int cnt = INT_MAX;
        if(i >= s1.length()) return 1 + solve(s1,s2,i,j+1);
        if(j >= s2.length()) return 1 + solve(s1,s2,i+1,j);
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = solve(s1,s2,i+1,j+1);

        int n1 = 1 + solve(s1,s2,i+1,j);
        int n2 = 1 + solve(s1,s2,i,j+1);

        return dp[i][j] = min(n1,n2);
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};