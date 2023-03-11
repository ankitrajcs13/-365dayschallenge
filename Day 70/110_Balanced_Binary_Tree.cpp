class Solution {
public:
    int height(TreeNode* root){
        if(!root)
            return 0;
        int lh = height(root -> left);
        int rh = height(root -> right);
        return max(lh, rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        bool lisBalance = isBalanced(root -> left);
        bool risBalance = isBalanced(root -> right);
        
        int lh = height(root -> left);
        int rh = height(root -> right);
        
        if(abs(lh-rh) <= 1 && lisBalance && risBalance)
            return true;
        return false;
    }
};