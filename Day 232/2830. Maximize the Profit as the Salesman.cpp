class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        // store the end and gold for every starting index

        map<int,vector<pair<int,int>>> freq;

        for(auto it:offers){
            freq[it[0]].push_back( {it[1],it[2]});
        }
        vector<int> dp(n);
        for(int i = 0; i<n; i++){
            vector<pair<int,int>>tmp = freq[i];
            if(i) dp[i] = max(dp[i], dp[i-1]);

            for(auto it:tmp){
                if(i) dp[it.first] = max(dp[it.first], dp[i-1] + it.second);
                // when it is the first house or profit
                else dp[it.first] = max(dp[it.first], it.second);
            }
        }
        return dp[n-1];
    }
};