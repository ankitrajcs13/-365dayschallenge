class Solution {
public:
    int dp[101][101];
    int solve(int st, int end, vector<int>& cuts, int left, int right){
        if(left > right) return 0;
        
        if(dp[left][right] != -1) return dp[left][right];
        int cost = 1e9;
        for(int i = left; i<= right; i++){
            int lCost = solve(st,cuts[i], cuts, left, i-1);
            int rCost = solve(cuts[i], end, cuts, i+1, right);
            int currCost = (end-st) + lCost + rCost;
            cost = min(cost,currCost);
        }
        return dp[left][right] = cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(), cuts.end());
        return solve(0,n, cuts,0,cuts.size() -1);
    }
};