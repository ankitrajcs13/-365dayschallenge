/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q) {
    if(root == NULL || root == P || root == Q){
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left,P,Q);
    TreeNode* right = lowestCommonAncestor(root->right,P,Q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else{ // means both left and right are not null
        return root;
    }
    
        
    }
};