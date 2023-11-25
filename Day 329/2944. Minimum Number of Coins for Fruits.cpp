class Solution {
public:
    
    int find(vector<int>& prices , int i , int tot, vector<vector<int>>&dp){
        
        int n = prices.size();
    
        if(i == n) return 0;
        if(dp[i][tot] != -1) return dp[i][tot];

        
        int ans1 = prices[i] + find(prices , i+1 , i+1,dp);
        
        int ans2 = 1e9;
        
        if(tot > 0)
          ans2 = find(prices , i+1 , tot-1,dp);
        
         int a =  min(ans1 , ans2);
        
         // dp[i][tot] = a;
      
        return dp[i][tot] = a;
    }
    
    int minimumCoins(vector<int>& prices) {
       int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(1e5,-1));
        return  find(prices,0,0,dp);
    }
};