class Solution {
public:

    bool bfs(vector<vector<int>>& graph, int i, vector<int> &color){
        queue<int> q;
        q.push(i);
        // put 1 to 1st node
        color[i] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                // means it is not visited yet
                if(color[it] == -1){
                    color[it] = 1 - color[node] ; // to put the opposite color of adj node
                    // like if its' adj has 1 then it will be 0, and if adj is 0 then it'll be 1
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       // to store 
       vector<int> color(n,-1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(!bfs(graph,i, color)) return false;
            }
        }
        return true;

    }
};