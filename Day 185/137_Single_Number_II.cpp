class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if (nums.size() % 3 != 0) {
            while (nums.size() % 3 != 0) {
                nums.push_back(0);
            }
        }
        int n = nums.size();
        for(int i = 0; i<n-2; i=i+3 ){
            if(nums[i] != nums[i+2] ) return nums[i];
        }
        return 0;
    }
};