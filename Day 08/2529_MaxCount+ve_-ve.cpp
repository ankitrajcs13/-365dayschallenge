class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pcnt = 0,ncnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0)
                ncnt++;
            else if(nums[i]>0)
                pcnt++;
            else
                continue;
        }
        return pcnt>ncnt? pcnt:ncnt;
    }
};

// TC- O(N)
// SC- O(1)