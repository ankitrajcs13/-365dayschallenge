class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i<n; i++){
            if( n % (i+1) == 0){
                res += nums[i] * nums[i];
            }
        }
        return res;
    }
};