/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int count = 0;  
  pair<int, int> solve(TreeNode* root) {
    if (root == nullptr) return {0, 0};  
    int subtreeSum = root->val;  
    int subtreeNodeCount = 1;   
    pair<int, int> leftSubtree = solve(root->left);
    pair<int, int> rightSubtree = solve(root->right);
    subtreeSum += leftSubtree.first + rightSubtree.first;
    subtreeNodeCount += leftSubtree.second + rightSubtree.second;
    if (root->val == (subtreeSum / subtreeNodeCount)) {
      count++;  
    }

    return {subtreeSum, subtreeNodeCount};
  }

  int averageOfSubtree(TreeNode* root) {
    pair<int, int> result = solve(root); 
    return count;  
  }
};