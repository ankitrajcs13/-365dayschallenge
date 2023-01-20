class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                // if we found any element which is equal
                // Increment count
                if(nums[i] == nums[j])
                    cnt++;
            }   
        }
        return cnt;
    }
};
// TC - O(N)
// SC- O(1)