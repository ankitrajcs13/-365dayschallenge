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
    int widthOfBinaryTree(TreeNode* root) {
        
        // using bfs traversal
        queue<pair<TreeNode*, int> > q;

        q.push({root,0});
        int res = 0;
        while(!q.empty()){
            int s = q.size();

            int fr,ls;
            int mini = q.front().second;
            for(int i = 0; i<s; i++){
                int curr = q.front().second - mini ;
                TreeNode* node = q.front().first;
                if(i == 0) fr = curr;
                if(i == s-1) ls = curr;
                q.pop();
                if(node->left)
                    q.push({node->left,(long long)curr*2+1});
                if(node->right)
                    q.push({node->right,2*(long long)curr+2});
            }
            res = max(res, ls-fr+1);
        }
        return res;


    }
};