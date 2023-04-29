class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int Ankires = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ankiMaxi = nums[n-1];
        for(int i = 0; i<k; i++){
            Ankires += ankiMaxi;
            ankiMaxi++;
        }
        return Ankires;
    }
};