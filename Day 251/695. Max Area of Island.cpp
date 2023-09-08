class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        queue<pair<int,int>>q;
        int n = grid.size(), m = grid[0].size();
        q.push({row,col});
        int cnt = 1;
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i =0 ;i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                    cnt++;
                }
                    
            }
        }
        return (cnt == 1)? cnt: cnt-1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res = INT_MIN, cnt = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int tmp = solve(i,j,grid,vis);
                    res = max(res,tmp);
                    // cnt++;
                }
            }
        }
        return (res == INT_MIN)? 0: res;
    }
};