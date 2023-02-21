class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());

        int e=nums.size()-1;
        int ans1=nums[e]*nums[e-1]*nums[e-2];
        int ans2=nums[e]*nums[0]*nums[1];

        int final=max(ans1,ans2);
        return final;

    }
};