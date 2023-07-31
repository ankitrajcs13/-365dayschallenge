class Solution {
public:
    long long solve(string &s1, string &s2, vector<vector<int>>&dp, int i, int j){
        if(i == s1.size() && j == s2.size()) return 0; // it means both strings are empty
       
        if(i == s1.size()){
            int sum = 0; 
            // if s1 is empty then calculate the ascii value of elements of s2
            for(int k = j; k<s2.size(); k++)
                sum+= (int)s2[k];
            return sum;
        }
        if(j == s2.size()){
            int sum = 0; 
            // if s1 is empty then calculate the ascii value of elements of s2
            for(int k = i; k<s1.size(); k++)
                sum+= (int)s1[k];
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j]; // dp memorization
        long long ans = INT_MAX;

        if(s1[i] == s2[j]) ans = solve(s1,s2,dp,i+1,j+1);
        else{
            ans = min(ans, s1[i] + solve(s1,s2,dp,i+1,j));
            ans = min(ans, s2[j] + solve(s1,s2,dp,i,j+1));
        }
        return dp[i][j] = ans;// memorization
    }
    
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(s1,s2,dp,0,0);
    }
};