class Solution {
public:

    int hig(TreeNode* root, int &res){
        if(root == NULL) return 0;

        int lh = hig(root->left,res);
        int rh = hig(root->right,res);
        res = max(res,lh+rh);
        return 1+max(lh,rh);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        hig(root,res);
        return res;


    }
};