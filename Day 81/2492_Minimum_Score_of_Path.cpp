class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            graph[u][v] = graph[v][u] = w;
        }
        
        int res = numeric_limits<int>::max();
        unordered_set<int> visited;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& [adj, score] : graph[node]) {
                if (!visited.count(adj)) {
                    q.push(adj);
                    visited.insert(adj);
                }
                res = min(res, score);
            }
        }
        
        return res;
    }
};