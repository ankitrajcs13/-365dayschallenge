class Solution {
public:
    
    void solve(int st, vector<int>& nums, vector<int> &tmp,vector<vector<int>> &res){
        res.push_back(tmp);
        for(int i = st; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            solve(i+1,nums,tmp,res);
            tmp.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        solve(0,nums,tmp,res);
        return res;
    }
};