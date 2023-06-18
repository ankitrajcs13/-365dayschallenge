class Solution {
public:
    int mod = 1e9 + 7;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool chk(int x, int y,vector<vector<int>>& grid){
        if(x<0 || x>=grid.size() || y < 0 || y >=grid[0].size()) return false;
        return true;
    }

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp){
        // memorization
        if(dp[x][y] != -1) return dp[x][y];

        int res = 1;
        for(int i = 0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if( chk(nx,ny,grid) && grid[nx][ny] > grid[x][y]){
                res = ( res + dfs(nx,ny,grid,dp));
            }
        }
        return dp[x][y] = res%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1 ));

        int cnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                cnt = (cnt%mod +  dfs(i,j,grid,dp)% mod);
            }
        }
        return cnt% mod;

    }
};