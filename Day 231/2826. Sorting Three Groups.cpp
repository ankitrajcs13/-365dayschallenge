class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        int ankicnt = 0;
        tmp.push_back(nums[0]);
        for(int i = 1; i<n; i++){
            auto al = lower_bound(tmp.begin(),tmp.end(),nums[i]);
            auto ah = upper_bound(tmp.begin(), tmp.end(),nums[i]);
            if(ah == tmp.end()) tmp.push_back(nums[i]);
            else{
                int ind = ah-tmp.begin();
                tmp[ind] = min(tmp[ind],nums[i]);
                ankicnt++;
            }
        }
        return ankicnt;
    }
};