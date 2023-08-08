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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return solve(root);
        TreeNode* tmp = root;

        // search the tree
        while(root){
            if(root->val > key){
                // then we have to move to left subtree
                if(root->left != NULL && root->left->val == key){
                    root->left = solve2(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = solve2(root->right);
                    break;
                }
                else root = root->right;
            }
        }
        return tmp;
    }
    TreeNode* solve(TreeNode* root){
        // check if either left or right subtree is null then directly connect
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        // we are cutting the right child and store it
        // finding the max node of left subtree
        // then point right of node to the removed right child
        TreeNode* rt = root->right;
        TreeNode* pred = findPre(root->left);
        pred->right = rt;
        return root->left;
    }
    TreeNode* solve2(TreeNode* root){
        // check if either left or right subtree is null then directly connect
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        // we are cutting the right child and store it
        // finding the max node of left subtree
        // then point right of node to the removed right child
        TreeNode* left = root->left;
        TreeNode* succ = findSucc(root->right);
        succ->left = left;
        return root->right;
    }
    TreeNode* findPre(TreeNode* root){
        if(root->right == NULL) return root;
        return findPre(root->right);
    }
    TreeNode* findSucc(TreeNode* root){
        if(root->left == NULL) return root;
        return findSucc(root->left);
    }
};