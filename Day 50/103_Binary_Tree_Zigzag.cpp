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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        queue<TreeNode*> q;
         vector<vector<int>> ans;

         // first push the root into the queue
         q.push(root);
        bool flag = true;
         while(!q.empty()){
             int n = q.size();
             vector<int> res;
             // Now traverse the tree till the size of queue
             for(int i = 0; i<n; i++){
                 TreeNode* temp = q.front();
                 res.push_back(temp->val);
                 q.pop();
                 if(temp->left)
                    q.push(temp->left);
                 if(temp->right)
                    q.push(temp->right);
             }
             if(!flag)
                reverse(res.begin(),res.end());
                // to make zig zag form
            flag = !flag;
             ans.push_back(res);
         }
         return ans;


    }
};