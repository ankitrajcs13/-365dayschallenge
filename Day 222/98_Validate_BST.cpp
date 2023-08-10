bool isValidBST(TreeNode* root){
        return solve(root, LONG_MIN,LONG_MAX);
}
bool solve(TreeNode* root, long mini, long maxi){
    if(root == NULL) return true;
    // check if the node is in the range
    if(root->val >= maxi || root->val <= mini) return false;
    return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
}