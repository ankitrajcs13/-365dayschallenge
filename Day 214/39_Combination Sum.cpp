class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, int remn, vector<int>& nums, vector<int> &tmp){
        // base case
        if(remn < 0) return ;
        else if( remn == 0) res.push_back(tmp);
        else{
            for(int i = start; i<nums.size(); i++){
                tmp.push_back(nums[i]);
                solve(i,remn-nums[i],nums,tmp); // it is again calling for ith (not i+1) bcz
                // repetetion is allowed
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        solve(0,target,candidates,tmp);
        return res;
    }
};