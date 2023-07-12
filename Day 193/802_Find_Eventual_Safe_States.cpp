class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> adj[n];
        vector<int> tmp(n);

        for(int i = 0; i<n; i++){
            for(auto x:graph[i]){
                adj[x].push_back(i);
                tmp[i]++;
            }
        }

        // bfs
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(tmp[i] == 0) q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            res.push_back(t);
            for(auto x:adj[t]){
                tmp[x]--;
                if(tmp[x] == 0) q.push(x);
            }
            
        }
        sort(res.begin(),res.end());
        return res;
    }
};