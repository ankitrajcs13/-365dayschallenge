class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int mini = nums[k];
        int res = 0;
        // edge case
        if(n == 1) return nums[0];
        while(i > 0 || j < n - 1){
            int lval = -1, rval = -1;

            if(i == 0) lval = 0;
            else lval = nums[i-1];

            if(j == n-1) rval = 0;
            else rval = nums[j+1];

            if(lval > rval){
                i--;
                mini = min(mini, lval);
            }
            else{
                j++;
                mini = min(mini,rval);
            }
            res = max ( res, mini * (j-i+1));
        }
        return res;
    }
};