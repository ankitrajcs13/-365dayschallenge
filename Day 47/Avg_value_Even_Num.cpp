class Solution {
public:
    int averageValue(vector<int>& nums) {
        int res = 0;
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 == 0 && nums[i]  % 3 == 0){
                res += nums[i];
                cnt++;
            }
        }
        if(cnt>0)
            res = res/cnt;
        return res;

    }
};