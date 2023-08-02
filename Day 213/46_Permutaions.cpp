class Solution {
public:
    vector<vector<int>> res;

    void solve(int st, vector<int> nums, vector<int> tmp){
        // base case
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int it: nums){
            if(find(tmp.begin(), tmp.end(), it)== tmp.end()){// it means element is not present
                tmp.push_back(it);
                solve(st,nums,tmp);
                tmp.pop_back();
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        solve(1,nums,tmp);
        return res;
    }
};