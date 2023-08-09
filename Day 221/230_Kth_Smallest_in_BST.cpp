class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                k--;
                if(k == 0){
                    ans = curr->val;
                }
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) prev = prev->right;

                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    k--;
                    if(k == 0) ans = curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};