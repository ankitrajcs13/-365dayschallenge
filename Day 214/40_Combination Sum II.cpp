class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, int remn, vector<int>& nums, vector<int> &tmp){
        // base case
        if(remn < 0) return ;
        else if( remn == 0) res.push_back(tmp);
        else{
            for(int i = start; i<nums.size(); i++){
                // to skip two adjacent elements which are same as there are duplicate elements
                if(i>start && nums[i] == nums[i-1]) continue;
                tmp.push_back(nums[i]);
                solve(i+1,remn-nums[i],nums,tmp); 
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        solve(0,target,candidates,tmp);
        return res;
    }
};