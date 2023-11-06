class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>>adjList(n);
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<int>take(n,-1), notTake(n,-1);
        return dfs(adjList, values, 0, -1).first;
    }
    pair<long long, long long> dfs(vector<vector<int>> &tree, vector<int>& values, int node, int parent){
        long long leftout = 0, taken = 0;
        for(auto c : tree[node]){
            if(c == parent) continue;
            auto [t, l] = dfs(tree, values, c, node);
            taken += t; leftout += l;
        }
        taken += (leftout != 0)?max(leftout, (long long)values[node]): 0;         //leftout 0 means its a leaf node and so we need to leave current nodeonly
        // taken += (long long)values[node];
        leftout = (leftout != 0)?min(leftout, (long long)values[node]): values[node];  
        //cout<<"node : "<<node<< " => "<<"taken : " <<taken<<", "<<"leftout : "<<leftout<<endl;  //Uncomment this line to see how the taken and leftout are changing 
        return {taken, leftout};
    }
};