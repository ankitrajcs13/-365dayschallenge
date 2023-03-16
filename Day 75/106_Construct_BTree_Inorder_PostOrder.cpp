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
    int postorderIndex;
    unordered_map<int, int> inorderIndexUmp;

    TreeNode* buildTreeHelper(vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;
        int rootValue = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootValue);
        int inorderPivotIndex = inorderIndexUmp[rootValue];
        // firstly call for right tree then for left tree 
        root -> right = buildTreeHelper(postorder, inorderPivotIndex + 1, right);
        root -> left = buildTreeHelper(postorder, left, inorderPivotIndex - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexUmp[inorder[i]] = i;
        }
        return buildTreeHelper(postorder, 0, postorder.size() - 1);
    }
};