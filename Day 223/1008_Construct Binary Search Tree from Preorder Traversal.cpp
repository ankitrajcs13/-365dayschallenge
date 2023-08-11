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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        map<int,int> mp;
        for(int i = 0; i<inorder.size(); i++)
            mp[inorder[i]]= i;
        
        TreeNode* root = solve(preorder, 0, preorder.size()-1,inorder,0,inorder.size()-1, mp);
        return root;
    }
    TreeNode* solve(vector<int>& preorder,int prest,int preend, vector<int>& inorder, int inst,int inend, map<int,int>& mp){
        // base case
        if(prest > preend || inst > inend) return NULL;
        // make the first element of preorder as a root
        TreeNode* root = new TreeNode(preorder[prest]);
        // now find the  position of root in inorder array
        int inRoot = mp[root->val];
        // now find the elements to it's left which will be the elements of left subtree
        int numsLeft = inRoot-inst;
        root->left = solve(preorder,prest+1,prest+numsLeft,inorder,inst,inRoot-1,mp);
        root->right= solve(preorder,prest+numsLeft+1,preend,inorder,inRoot+1,inend,mp);
        return root;
    }
};