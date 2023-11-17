class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        int res =0 ;
        sort(nums.begin(), nums.end());
        while(i< n){  
            int sum = nums[i++] + nums[j--];
            res = max(res,sum);
        }
        return res;
    }
};