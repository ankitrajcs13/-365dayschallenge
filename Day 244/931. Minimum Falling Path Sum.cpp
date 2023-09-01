class Solution {
public:
    int f(int i, int j, vector<vector<int>>& a, vector<vector<int>>&dp ){
        int n = a.size(),m = a[0].size();
        // base case
        if(j<0 || j>(a.size()-1))return 1e9;
        if(i==0) return a[i][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int up =  f(i-1,j,a,dp);
        int ld =  f(i-1,j-1,a,dp);
        int rd =  f(i-1,j+1,a,dp);
        return dp[i][j]=a[i][j]+min(up,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        int res = INT_MAX;
        for(int j = 0; j<n; j++){
            vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
            // why not -1 ->
            // This is happening because -1 can also be considered in taking the min sum so its deviating the answer hence we'd taken INT_MIN to initialise the dp.
            int tmp = f(n-1,j,matrix,dp);
            res = min(res,tmp);
        }
        return res;
    }
};