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
    vector<TreeNode*> solve(int st, int end){
        // base case
        if(st > end) return {NULL};
        vector<TreeNode*> res;
        for(int i = st; i<= end; i++){
            // call for left and right subtrees
            vector<TreeNode*> lft = solve(st, i-1);
            vector<TreeNode*> rgt = solve(i+1,end);

            for(auto lt: lft){
                for(auto rt: rgt){
                    TreeNode* node = new TreeNode(i);
                    node->left = lt;
                    node->right = rt;
                    res.push_back(node);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};