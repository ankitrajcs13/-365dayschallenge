class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target) return 0;
        map<int, vector<int>> adj;

        for(int i = 0; i<routes.size(); i++){
            for(auto it:routes[i])
                adj[it].push_back(i);
        }
        queue<int>q;
        unordered_set<int>vis;
        for(auto it:adj[source]){
            q.push(it);
            vis.insert(it);
        }

        int cnt = 1;
        while(q.size()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                int r = q.front();
                q.pop();
                for(auto it:routes[r]){
                    if(it == target) return cnt;
                
                    for(auto nxt:adj[it]){
                        if(!vis.count(nxt)){
                            q.push(nxt);
                            vis.insert(nxt);
                        }
                    }

                }
            }
            cnt++;
        }
        return -1;

    }
};