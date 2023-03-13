class Solution {
public:
    bool solve(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left ->val != right ->val) return false;
        //if(left != NULL || right != NULL) return false;

        return solve(left->left,right->right) && solve(left->right, right->left);

    }

    bool isSymmetric(TreeNode* root) {
          return solve(root->left,root->right);
    }
};