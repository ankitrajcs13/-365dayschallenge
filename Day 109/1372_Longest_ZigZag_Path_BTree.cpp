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
public:
    int ans = 0;
    
    int dfs(TreeNode* root, bool left) {
        if (!root) return -1;
        
        int l =1+dfs(root->left, false);
        int r =1+dfs(root->right, true);
        ans = max(ans, max(l, r));
        
        return left ? l : r ;
    }
    int longestZigZag(TreeNode* root) {
        dfs(root, true); 
        return ans;
    }
};