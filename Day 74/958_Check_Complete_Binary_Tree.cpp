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
    bool isCompleteTree(TreeNode* root) {
        // base case
        if(root == NULL) return true;

        // using BFS traversal
        queue<TreeNode*> q;

        q.push(root);

        while(q.front() != NULL){
            TreeNode* tmp = q.front();
            q.pop();

            q.push(tmp->left);
            q.push(tmp->right);
        }
        // check for left or right
        while(!q.empty() && q.front()== NULL) q.pop();
        

        if(q.empty()) return true;
        return false;


    }
};