class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, int>>> graph;
        
        // Build the graph using an adjacency list representation
        // Each edge is represented as a pair (neighbor node, edge index)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], edgeIdx = i;
            graph[u].push_back({v, edgeIdx});
            graph[v].push_back({u, edgeIdx});
        }
        
        vector<double> probabilities(n, 0.0);
        probabilities[start] = 1.0;
        
        priority_queue<pair<double, int>> nodesToExplore;
        // Add the start node to the priority queue with probability 1.0
        nodesToExplore.push({1.0, start});
        
        while (!nodesToExplore.empty()) {
            auto [prob, u] = nodesToExplore.top();
            nodesToExplore.pop();
            
            // If we've reached the end node, return the probability
            if (u == end) 
                return prob;
            // If we've already explored this node with a higher probability, skip it
            if (probabilities[u] > prob) 
                continue;
                
            // Explore the neighbors of the current node
            for (auto [v, edgeIdx] : graph[u]) {
                double newProb = prob * succProb[edgeIdx];
                
                // Update the probability of the neighbor node if we've found a higher probability
                if (newProb > probabilities[v]) {
                    probabilities[v] = newProb;
                    
                    // Add the neighbor node to the priority queue with its new probability
                    nodesToExplore.push({newProb, v});
                }
            }
        }
        
        // If we've explored all nodes and haven't reached the end node, return 0.0
        return 0.0;
    }
};