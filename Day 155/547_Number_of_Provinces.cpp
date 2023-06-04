class Solution {
public:
    // by dfs
    void dfs(int n, vector<vector<int>> &isConnected, vector<bool> &vis){
        vis[n] = true;
        for(int i = 0; i< isConnected.size(); i++){
            if(isConnected[n][i] && !vis[i]) dfs(i,isConnected,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        vector<bool> visit(n);
        // using dfs we're checking is it connected or not
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                res++;
                dfs(i, isConnected, visit);
            }
        }

        return res;
    }
};