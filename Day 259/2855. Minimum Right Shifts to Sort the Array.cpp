class Solution {
public:
    
    int minimumRightShifts(vector<int>& nums) {
        vector<int> srt = nums;
        int nsrt = nums.size();
        sort(srt.begin(), srt.end());
        for(int i = 0; i<nsrt; i++){
            if(nums == srt) return i;
            rotate(srt.begin(),srt.begin()+1, srt.end());
        }
        return -1;
    }
};