class BSTIterator {
private: stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* tmp = st.top();
        st.pop();
        pushLeft(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
private: void pushLeft(TreeNode* root){
    while(root){
        st.push(root);
        root= root->left;
    }
}
};