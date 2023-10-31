class Solution {
public:
    int res = 0;
    pair<bool,int> dfs(TreeNode* root, int start){
        if(!root) return {false,0};
        pair<bool,int>p1 = dfs(root->left,start);
        pair<bool,int>p2 = dfs(root->right,start);

        if(root->val==start){
            int temp = max(p2.second,p1.second);
            res = max(res,temp);
            return {true,0};
        }

        if(p1.first){
            int sum = p1.second+p2.second+1;
            res = max(res,sum);
            return {true,p1.second+1};
        }else if(p2.first){
            int sum = p1.second+p2.second+1;
            res = max(res,sum);
            return {true,p2.second+1};
        }
        int sum = max(p1.second,p2.second);
        return {false,sum+1};
    }
    
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return res;
    }
};