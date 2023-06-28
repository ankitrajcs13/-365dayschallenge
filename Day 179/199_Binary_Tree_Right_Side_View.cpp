class Solution {
public:
    void solve(TreeNode* root, int level, vector<int> &res){
        if(root == NULL) return;

        if(level == res.size()) res.push_back(root->val);
        if(root->right) solve(root->right,level+1,res);
        if(root->left) solve(root->left,level+1,res);

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        solve(root,0,res);
        return res;
    }
};