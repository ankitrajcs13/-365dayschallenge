class Solution {
public:
    vector<vector<int>> dp;
    int f(int idx,int k,vector<vector<int>>& arr){
        if(idx==arr.size()||k==0)
        return 0;

        if(dp[idx][k]!=-1)
        return dp[idx][k];

        vector<int> temp={arr[idx][1]+1,0,0};
        int j=lower_bound(arr.begin(),arr.end(),temp)-arr.begin();

        return dp[idx][k]=max(f(idx+1,k,arr),arr[idx][2]+f(j,k-1,arr));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        dp=vector<vector<int>>(events.size(),vector<int>(k+1,-1));

        return f(0,k,events);
    }
};