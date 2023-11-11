class Graph {
public:
int dijkstra(int start, int end) {
        int n = adjacencyList.size();
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        // Priority queue to efficiently retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, start});

        while (!priorityQueue.empty()) {
            int currentNode = priorityQueue.top().second;
            int currentCost = priorityQueue.top().first;
            priorityQueue.pop();
            if (currentCost > distances[currentNode])
                continue;

            // If found the target node then return the cost
            if(currentNode == end)
                return currentCost ;

            // Explore neighbors and update distances
            for (auto edge : adjacencyList[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + distances[currentNode];

                // Update distance if a shorter route is found
                if (distances[neighbor] > newRouteCost) {
                    distances[neighbor] = newRouteCost;
                    priorityQueue.push({newRouteCost, neighbor});
                }
            }
        }

        // Return the minimum distance or -1 if no path exists
        return ((distances[end] == INT_MAX) ? -1 : distances[end]);
    }
    vector<vector<pair<int, int>>> adjacencyList;
    Graph(int n, vector<vector<int>>& edges) {
        adjacencyList.resize(n);
        for (auto edge : edges)
            adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }
};