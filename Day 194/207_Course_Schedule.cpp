class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses);
       vector<vector<int>> adj(numCourses);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indeg[prerequisite[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        //BFS
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cnt++;
            
            for(auto neigh:adj[node]){
                indeg[neigh]--;
                if(indeg[neigh] == 0) q.push(neigh);
            }
        }
        
        if(cnt == numCourses) return true;
        return false;
        
    }
};