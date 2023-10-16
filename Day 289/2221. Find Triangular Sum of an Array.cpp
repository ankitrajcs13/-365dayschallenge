class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>res = nums;
        for(int i = 0; i<n; i++){
            int sz = n-i-1;
            vector<int>tmp(sz,0);
            for(int j = 0; j<sz; j++){
                tmp[j] = (res[j] + res[j+1]) % 10;
            }
            res = tmp;
            if(res.size() == 1){
                break;
            }
        }
        return res[0];
    }
};