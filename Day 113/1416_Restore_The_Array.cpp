class Solution {
    long long mod=1e9+7;
public:
    int solve(string &s,int k,int i,vector<int>&dp){
        if(i>=s.size())return 1;
        if(s[i]=='0')return 0;
        int ans=0;
        if(dp[i]!=-1)return dp[i];
        long long d=0;
        for(int j=i;j<s.size();j++){
            d= d*10 + (s[j]-'0');
            if(d>k)break;
            ans = (ans%mod + solve(s,k,j+1,dp)%mod)%mod;
        }
        dp[i]=ans;
        return ans;
    }
    int numberOfArrays(string s, int k) {
       vector<int>dp(s.size()+1,-1);
        return solve(s,k,0,dp);
    }
};