class Solution {
public:
    void solve(TreeNode* root, vector<int>&inOrder){
        if(root == NULL) return;
        solve(root->left,inOrder);
        inOrder.push_back(root->val);
        solve(root->right,inOrder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inOrder;
        solve(root,inOrder);
        return inOrder;
    }
};