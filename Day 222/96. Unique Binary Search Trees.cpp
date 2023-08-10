class Solution {
public:
    int dp[100];
    int fact(int n) {
        if(n == 0) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += fact(i-1) * fact(n-i);
        return dp[n] = ans;
}
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));

        return fact(n);

    }
};