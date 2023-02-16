class Solution {
public:
  
    int maxDepth(TreeNode* root) {
        int ans = 0;
        // edge case
        if(root == NULL) return 0;
        ans = max( maxDepth(root->left), maxDepth(root->right) );
        return ans+1;
    }
};