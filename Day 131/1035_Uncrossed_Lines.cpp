class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

        for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0; 
            } else if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            }
        }
        return dp[n1][n2];
    }
};