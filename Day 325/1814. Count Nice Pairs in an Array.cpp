class Solution {
public:
    int rev(int num){
        int res = 0;
        while(num>0){
            res = res * 10 + num % 10;
            num/=10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        vector<int>arr;
        for(int i = 0; i<nums.size(); i++){
            arr.push_back(nums[i] - rev(nums[i]));
        }
        map<int,int>mp;
        int ans = 0;
        int mod = 1e9+7;
        for(int it:arr){
            ans = ( ans + mp[it]) % mod;
            mp[it]++;
        }
        return ans;
    }
};