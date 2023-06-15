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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int lvl = 0;
        q.push(root);
        // apply bfs
        int maxi = INT_MIN, ans = 1;
        while(!q.empty()){
            lvl++;
            int sz = q.size();
            int sum = 0;
            while(sz--){
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum > maxi){
                ans = lvl;
                maxi = sum;
            }
        }
        return ans;
    }
};