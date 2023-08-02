class Solution {
public:
    vector<vector<int>> res;
    void solve(int st, vector<int> &nums, vector<int>& tmp){
        res.push_back(tmp);
        for(int i = st; i<nums.size(); i++){
            //check for duplicate elements
            if(i>st && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            solve(i+1,nums,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        // to get the duplicate elements at one place
        sort(nums.begin(), nums.end());
        solve(0,nums,tmp);
        return res;
    }
};