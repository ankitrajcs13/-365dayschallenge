class Solution {
public:
    int arraySign(vector<int>& nums) {
        int nCnt = 0, oCnt= 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < 0) nCnt++;
            else if(nums[i] == 0) return 0;
            else oCnt++;
        }
        if(nCnt % 2 == 0) return 1;
        else return -1;
        
    }
};