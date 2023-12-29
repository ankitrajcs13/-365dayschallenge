class Solution {
public:
    int dp[301][11];
    int solve(int ind, int d, vector<int>&j){
        int n = j.size();
        if(d == 1){
            int maxi = j[ind];
            for(int i = ind; i<n; i++){
                maxi = max(maxi,j[i]);
            }
            return maxi;
        }
        if(dp[ind][d] != -1) return dp[ind][d];
        int maxi = INT_MIN, fin = INT_MAX;
        for(int i = ind; i<=n-d; i++){
            maxi = max(maxi,j[i]);
            int result = maxi + solve(i+1,d-1,j);
            fin = min(fin,result);
        }
        return dp[ind][d] = fin;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // edge case
        if(jobDifficulty.size() < d) return -1;
        memset(dp,-1,sizeof(dp));
        return solve(0,d,jobDifficulty);
    }
};