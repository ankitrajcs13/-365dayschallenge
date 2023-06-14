class Solution {
public:

vector<int> v;

    void inorder(TreeNode* root){
        if(root == NULL) return ;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int res = INT_MAX;
        for(int i = 0; i<v.size()-1; i++)
            res = min(res, v[i+1]- v[i]);
        return res;
    }
};