class Solution {
public:

    void inOrder(TreeNode* root, int &mini, int &preVal){
        if(root == NULL)
            return ;
        inOrder(root->left,mini,preVal);
        if(preVal != -1)
            mini = min(mini, root->val-preVal);
        preVal = root->val;
        inOrder(root->right,mini,preVal);
    }

    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        int preVal = -1;
        
        inOrder(root, mini,preVal);
        return mini;

    }
};