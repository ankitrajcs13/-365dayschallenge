// Brute Force 
class Solution {
public:
    void solve(TreeNode* root, vector<int>&in){
        if(!root) return;

        if(root->left) solve(root->left,in);
        in.push_back(root->val);
        if(root->right) solve(root->right,in);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        solve(root,in);

        int i = 0, j = in.size()-1;
        while(i < j){
            int s= in[i] + in[j];
            if(s == k) return true;
            else if( s > k) j--;
            else i++;
        }
        return false;
    }
};

// Optimised
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
class BSTIterator {
private: stack<TreeNode*> st;
            bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushLeft(root);
    }
    
    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        if(!reverse) pushLeft(tmp->right);
        else pushLeft(tmp->left);
        return tmp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
private: void pushLeft(TreeNode* node){
    for(; node!= NULL;){
        st.push(node);
        if(reverse == true){ // if it is reverse then go to right
            node = node->right;
        }
        else node = node->left;
    }
}
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i + j == k) return true;
            else if(i+j < k ) i = l.next();
            else j = r.next();
        }
        return false;
    }
};