class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n);
        vector<bool> fb(n,false);
        for(auto v:edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        for(int r:restricted) fb[r]=true;
        queue<int> qq;
        qq.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        int ans=0;
        while(qq.size()){
            int p=qq.front();
            qq.pop();
            ans++;
            for(int ne:g[p]){
                if(vis[ne]||fb[ne]) continue;
                vis[ne]=true;
                qq.push(ne);
            }
        }
        return ans;
    }
};