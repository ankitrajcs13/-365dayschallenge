class Solution {
public:

    int solveLeft(TreeNode* root, int ans){
        // edge case
        if(root == NULL) return 0;

        ans = ans * 10 + root->val;
        // check for child nodes
        if(!root ->left && !root->right) return ans;
        int left = solveLeft(root->left, ans);
        int right = solveLeft(root->right,ans);
        return left + right;

    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        return solveLeft(root, ans);
    }
};