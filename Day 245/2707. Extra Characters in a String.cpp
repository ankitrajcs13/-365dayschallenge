class Solution {
public:
    int f(int idx,string s, unordered_map<string,int>&mp,vector<int>&dp){
        // base case
        if(idx >=s.size()) return 0;
        // memoize
        if(dp[idx] != -1)return dp[idx];
        int ans = 1e9;
        string res = "";
        for(int i = idx;i <s.size(); i++){
            res+=s[i];
            int cnt = ((mp.count(res)) ? 0 : res.size()) + f(i+1,s,mp,dp);
            ans = min(ans,cnt);
        }
        return dp[idx] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(auto it:dictionary) mp[it]++;
        vector<int>dp(s.size(),-1);
        return f(0,s,mp,dp);
    }
};