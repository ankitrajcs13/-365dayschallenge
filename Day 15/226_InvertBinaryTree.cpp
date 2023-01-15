/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        void solve(TreeNode* root){
            // base case to terminate
        if(root == NULL)
            return;
        // store the left of tree in a temporary node pointer
        TreeNode* temp = root->left;
        // then exachange the position of right tree to left
        root->left = root->right;
        // Similarly change the position of left tree to right with the help of temporary pointer
        root->right = temp;
        // Then call the recursion to solve all the cases.
        // As while using recursion we have to solve only one case. Else all the cases will
        // be solved by recursion. We don't have to worry about it
        solve(root->left);
        solve(root->right);
        }
public:
    TreeNode* invertTree(TreeNode* root) {
        
        solve(root);
        return root;

    }
};