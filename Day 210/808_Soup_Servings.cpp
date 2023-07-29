class Solution {
public:

    unordered_map<int, unordered_map<int, double>> dp;
        double prob(int i, int j){
        if (i <= 0 && j <= 0) return 0.5;
        if (i <= 0) return 1;
        if (j <= 0) return 0;
        if (dp[i].count(j)) return dp[i][j];
        return dp[i][j] = (prob(i - 4, j) + prob(i - 3, j - 1) +
            prob(i - 2, j - 2) + prob(i - 1, j - 3)) /4;

    }
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        for (int k = 1; k <= m; k++) {
        if (prob(k, k) > 1 - 1e-5) {
        return 1;
        }
        }
        return prob(m, m);
    }
};