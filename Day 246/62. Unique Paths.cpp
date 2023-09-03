class Solution {
public:
    int dp[100][100];
    int f(int i, int j){
        if(i == 0 && j == 0) return 1;
        if(i<0 || j < 0) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = f(i-1,j) + f(i,j-1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>v(m,vector<int>(n,-1));
        // dp[0][0] = 1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 && j == 0)dp[i][j] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};