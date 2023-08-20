class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj, vector<int>& indegree)  {
	    queue<int> que;
	    for(int i = 0; i < adj.size(); i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	        }
	    }
	    vector<int> result;
	    while(!que.empty()) {
	        int u = que.front();
	        result.push_back(u);
	        que.pop();
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	            }
	            
	        }
	    }
	    
	    return result.size() == adj.size() ? result : vector<int>();
	}
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        
        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }
        
        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(m, 0);
        for (int i = 0; i < m; ++i) {
            groupGraph[i] = vector<int>();
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {
                itemGraph[prev].push_back(i);
                itemIndegree[i]++;
                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];
                    groupGraph[prevItemGroup].push_back(currItemGroup);
                    groupIndegree[currItemGroup]++;
                }
            }
        }
        vector<int> itemOrder  = topoSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);
        
        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }
        
        unordered_map<int, vector<int>> groupToItemsInOrder;
        for (int item : itemOrder) {
            int itemGroup = group[item];
            groupToItemsInOrder[itemGroup].push_back(item);
        }
        
        vector<int> result;
        for (int group : groupOrder) {
            result.insert(result.end(), groupToItemsInOrder[group].begin(), groupToItemsInOrder[group].end());
        }
        return result;
    }
};