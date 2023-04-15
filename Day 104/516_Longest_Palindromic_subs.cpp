class Solution {
private:
    vector<vector<int>> dp;
    
    int rec(string &s, string &rev, int i, int j) {
        if(i == s.length() || j == rev.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == rev[j])
            return dp[i][j] = 1 + rec(s, rev, i + 1, j + 1);
        return dp[i][j] = max(
            rec(s, rev, i + 1, j),
            rec(s, rev, i, j + 1)
        );
    }
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(s.begin(), s.end());
        
        int size = s.size();
        
        dp.resize(size + 1, vector<int>(size + 1, -1));
        
        return rec(s, rev, 0, 0);
    }
};