class Solution {
public:

    // top down

    // vector<int> dp;
    // int helper2(vector<int> arr, int i){
    //     if(i==0 || i==1) return 0;

    //     if(dp[i]!=-1) return dp[i];

    //     if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]){
    //         return dp[i] = helper2(arr,i-1)+1;
    //     }else return dp[i] = 0;
    // }

    int helper(vector<int> arr){
        int n = arr.size();

        int dp[n];
        dp[0] = 0;
        dp[1] = 0;
        int ans = 0;
        for(int i=2; i<n; i++){
            if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]){
                dp[i] = dp[i-1] + 1;
            }else dp[i] = 0;
            ans = ans + dp[i];
        }
        return ans;
    }
    int numberOfArithmeticSlices(vector<int>& arr) {
        if(arr.size()<3) return 0;
        return helper(arr);    // bottom up

        // top down

        // dp.resize(5005,-1);
        // int ans = 0;
        // for(int i=2; i<arr.size(); i++){
        //     ans = ans + helper2(arr,i);
        // }
        // return ans;
    }
};