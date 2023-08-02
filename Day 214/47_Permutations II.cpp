class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums,  vector<int> &tmp, vector<bool> &used){
        // check if size is equal
        if(tmp.size() == nums.size()) res.push_back(tmp);
        else{
            for(int i = 0; i<nums.size(); i++){
                 if(used[i] || i> 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

                tmp.push_back(nums[i]);
                used[i] = true;
                solve(nums,tmp,used);
                used[i]= false;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        solve(nums,tmp,used);
        return res;

    }
};