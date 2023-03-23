class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // edge case
        if(connections.size() < n -1 ) return -1;
        
        // now take one visited array
        vector<int> vis(n,0);
        // creating adjacency list 
        unordered_map<int, vector<int> > mp;
        for(auto it: connections){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        // it will be initially -1
        int cnt = -1;
        // now traverse it using DFS
        for(int i = 0; i< n; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                cnt++;
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    for(auto it: mp[tmp]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return cnt;





    }
};