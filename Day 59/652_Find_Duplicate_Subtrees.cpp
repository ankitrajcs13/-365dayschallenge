class Solution {

    

    string solve(TreeNode* root, unordered_map<string,int>&mp, vector<TreeNode*> &res){
        if(root == NULL) return "";
         
        string left = solve(root->left,mp,res);
        string right = solve(root->right,mp,res);
        const string s = to_string(root->val) + "#" + left + "#" + right;


        if(++mp[s] == 2){// duplicate nodes        
            res.push_back(root);
        }
        return s;

    }


public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> res;
        unordered_map<string,int> mp;
        solve(root,mp,res);
        return res;

    }
};