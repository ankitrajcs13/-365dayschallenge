
class Solution {
public:
    int longestPalindromeSubstring(string& s, int i, int j, vector<vector<int>>& memo) {
        if (i > j)
            return 0;
        else if (i == j)
            return 1;
        else if (memo[i][j] != -1)
            return memo[i][j];
        else if (s[i] == s[j])
            return memo[i][j] = 2 + longestPalindromeSubstring(s, i+1, j-1, memo);
        else
            return memo[i][j] = max(longestPalindromeSubstring(s, i+1, j, memo), longestPalindromeSubstring(s, i, j-1, memo));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        int minNumSteps = n - longestPalindromeSubstring(s, 0, n-1, memo);
        return minNumSteps;
    }
};