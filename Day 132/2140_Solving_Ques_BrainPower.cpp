class Solution {
public:

    long long helper(int idx,  vector<long long> &dp, vector<vector<int>>& questions){
        // base case
        if(idx >= questions.size()) return 0;
        // using memorization
        if(dp[idx] != -1) return dp[idx];

        long long take = questions[idx][0] + helper(idx + questions[idx][1] + 1,dp,  questions);
        long long skip = helper(idx+1,dp, questions);

        return dp[idx] = max(take,skip);


    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return helper(0,dp , questions);
    }
};