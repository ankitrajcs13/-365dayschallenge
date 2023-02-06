class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // create an answer array of size 2n to store the shuffled array
        vector<int> ans(n*2);
        // iterate the nums array and store the values in ans array accordingly
        for(int i = 0; i<n; i++){
            // even case
            ans[2*i] = nums[i];

            //odd case
            ans[2*i+1] = nums[n+i];
        }
        return ans;
    }
};
// TC - O(N)
// SC- O(N)