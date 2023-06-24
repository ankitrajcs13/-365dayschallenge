class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue< pair<TreeNode*, pair<int,int>>> q;
        // we will start from root initially
        q.push({root,{0,0}});
        map<int, map<int,multiset<int>>> mp;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            TreeNode* tmp = node.first;
            // x is the vertical and y is the level
            int x = node.second.first, y = node.second.second;
            mp[x][y].insert(tmp->val);
            if(tmp->left) 
                q.push({tmp->left,{x-1,y+1}});
            if(tmp->right)
                q.push({tmp->right,{x+1,y+1}});

        }

        // after traversing the tree by level order
        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> col;
            for(auto q:it.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};