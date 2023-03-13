class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int cnt = 0;
        long sum = 0;
        // start from last element
        for(int i = nums.size()-1; i>=0; i--){
            sum += nums[i];
            if(sum > 0) cnt++;
        }
        return cnt;
            
    }
};
// TC - O(N)
// SC - O(1)