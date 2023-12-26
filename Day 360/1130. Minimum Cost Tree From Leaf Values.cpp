class Solution {
public:

    int mctFromLeafValuesRec(vector<int>& arr,map<pair<int,int>,int>& maxi,int left,int right)
    {
        // Base Case -- Leaf Node
        if(left == right)
            return 0;
        
        int ans = INT_MAX;
        for(int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left,i}] * maxi[{i+1,right}] + mctFromLeafValuesRec(arr,maxi,left,i) + mctFromLeafValuesRec(arr,maxi,i+1,right));
        }

        return ans;
    }

    // TC - O(N*3) and SC - O(N*2)
    int mctFromLeafValuesMem(vector<int>& arr,map<pair<int,int>,int>& maxi,int left,int right,vector<vector<int>>& dp)
    {
        // Base Case -- Leaf Node
        if(left == right)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        
        int ans = INT_MAX;
        for(int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left,i}] * maxi[{i+1,right}] + mctFromLeafValuesMem(arr,maxi,left,i,dp) + mctFromLeafValuesMem(arr,maxi,i+1,right,dp));
        }

        dp[left][right] = ans;
        return dp[left][right];
    }

    // TC - O(N*3) and SC - O(N*2)
    int mctFromLeafValuesTab(vector<int>& arr,map<pair<int,int>,int>& maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int left = n - 1; left >= 0; left--)
        {
            for(int right = 0; right <= n - 1; right++)
            {
                // Invalid Range
                if(left >= right)
                continue;
                
                int ans = INT_MAX;
                for(int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left,i}] * maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
                }

                dp[left][right] = ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int> maxi;
        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            maxi[{i,i}] = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }

        // 1. Recursion
        // return mctFromLeafValuesRec(arr,maxi,0,n-1);

        // 2. Top Down Approach
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return mctFromLeafValuesMem(arr,maxi,0,n-1,dp);

        // 3. Bottom Up Approach
        return mctFromLeafValuesTab(arr,maxi);
    }
};