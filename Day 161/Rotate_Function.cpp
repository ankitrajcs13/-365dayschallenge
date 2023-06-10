class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        vector<int> f(n, 0);
        int sum=0;
        for(int j=0;j<n;j++)
        {
            f[0] += j * nums[j];
            sum += nums[j];
        }
        
        for(int i=1;i<n;i++)
        {
            f[i] = f[i-1] + sum - (n)*nums[n-i];
        }

        for(int i:f)
        ans = max(ans, i);
        return ans;
    }
};