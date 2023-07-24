class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr) {
            return;
        }
        
        path.push_back(root->val);
        
        if (root->val == targetSum && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        }
        
        solve(root->left, targetSum - root->val, path, ans);
        solve(root->right, targetSum - root->val, path, ans);
        
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> ans;
        
        solve(root, targetSum, path, ans);
        
        return ans;
    }
};