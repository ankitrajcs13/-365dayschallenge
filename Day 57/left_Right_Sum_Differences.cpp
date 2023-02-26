class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
       int left[n];
        left[0] = 0;
        for(int i = 0;i<nums.size()-1; i++){
            left[i+1] = nums[i] + left[i];
        }
        reverse(nums.begin(),nums.end());
        int right[n];
        right[0] = 0;
        for(int i = 0;i<nums.size()-1; i++){
            right[i+1] = nums[i] + right[i];
        }
        reverse(right,right+n);
        vector<int> ans;
        for(int i = 0; i<n; i++)
            ans.push_back(abs(right[i]-left[i]));
        return ans;
        
    }
};