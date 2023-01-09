class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        
        int cnt = 0;
        for(int i =0; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){

            
            int d = abs(nums[i] - nums[j]);
            if(d == k)
                cnt++;
            }
        }
        return cnt;

    }
};

// TC - O(N^2)
// SC - O(1)