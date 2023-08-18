class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxi = 0;
        unordered_map<int,unordered_set<int>>adj;

        for(auto road:roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int curr = adj[i].size() + adj[j].size();
                if(adj[i].find(j) != adj[i].end()) curr--;
                maxi = max(maxi,curr);
            }
        }
        return maxi;
    }
};