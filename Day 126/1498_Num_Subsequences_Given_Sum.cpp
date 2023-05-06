class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        int l = 0, r = n-1;
        // we have to sort the array
        sort(nums.begin(),nums.end());
        vector<int> pow(n,1);
        for(int i = 1; i<n; i++)
            pow[i] = pow[i-1] * 2 % 1000000007;

        while(l <= r){
            if(nums[l] + nums[r] > target) r--;
            else{
                ans = (ans + pow[r - l++]) % 1000000007;
            }
        }
        return ans % 1000000007;
    }
};