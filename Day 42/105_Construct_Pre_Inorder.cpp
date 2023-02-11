class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &idx,int st, int end){
        // base case
        if(st > end) return NULL;

        // index for preOrder
        int preInd = st;


        while(inorder[preInd] != preorder[idx])
            preInd++;

        idx++;
        TreeNode* tmp = new TreeNode(inorder[preInd]);
        // int ind = find(inorder,st,end,tmp->val);

        tmp->left = solve(preorder,inorder,idx,st, preInd-1);
        tmp->right = solve(preorder,inorder,idx, preInd+1,end);
        return tmp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return solve(preorder,inorder,idx,0,inorder.size()-1);
    }
    
};