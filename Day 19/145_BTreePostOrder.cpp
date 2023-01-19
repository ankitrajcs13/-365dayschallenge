class Solution {
  
public:
  vector<int> v;
        void postOrder(TreeNode* root){
            // base case
            if(root == NULL)
                return;
            postOrder(root->left);
            postOrder(root->right);
            v.push_back(root->val);
        }
    vector<int> postorderTraversal(TreeNode* root) {
        
        postOrder(root);
        return v;

        
        
    }
};