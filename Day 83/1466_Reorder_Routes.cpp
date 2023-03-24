class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n) , bk(n);
        vector<int> vis(n,0);
        vis[0] =1;
        for(auto a : con){
            adj[a[0]].push_back(a[1]);
            bk[a[1]].push_back(a[0]);
        }
        int ans=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int a = q.front();
            vis[a] =1;
            q.pop();
            for( int no : adj[a]){
                if(!vis[no]){
                    ans++;
                    q.push(no);
                }
            }
            for( int no : bk[a]){
                if(!vis[no]){
                    q.push(no);
                }
            }
        }
        return ans;
    }
};