class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>>adj;

        for(auto it:adjacentPairs){
            int u = it[0];
            int v= it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // find the root node
        int root = 0;
        for(auto it:adj){
            if(it.second.size() == 1){
                root = it.first;
                break;
            }
        }
        vector<int>ans;
        set<int>vis;
        dfs(root,ans,adj,vis);
        return ans;
    }
    void dfs(int root, vector<int>&ans, map<int, vector<int>>&adj,set<int>&vis ){
        ans.push_back(root);
        vis.insert(root);
        for(auto it: adj[root]){
            if(vis.find(it) == vis.end()){
                dfs(it,ans,adj,vis);
            }
        }
    }
};