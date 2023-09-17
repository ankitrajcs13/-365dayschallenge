class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int maxMask = (1 << n) -1;
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> s;   
        for(int i = 0; i < n; i++){
            int mask = (1 << i);
            q.push({i, {0, mask}}); 
            s.insert({i, mask}); 
        }
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second.first;
            int mask = q.front().second.second;
            q.pop();
            for(auto it : graph[node]){
                int newMask = mask | (1 << it);
                if(newMask == maxMask) return dis + 1;
                if(s.count({it, newMask})) continue;
                q.push({it, {dis + 1, newMask}});
                s.insert({it, newMask});
            }
        }
        return 0;
    }
};