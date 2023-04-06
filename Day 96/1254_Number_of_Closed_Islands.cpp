class Solution {
public:

    bool dfs(int x, int y, int m, int n,  vector<vector<bool>> & visit,vector<vector<int>> &grid) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        if (grid[x][y] == 1 || visit[x][y]) {
            return true;
        }

        visit[x][y] = true;
        bool isClosed = true;
        vector<int> dirx {0, 1, 0, -1};
        vector<int> diry {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int r = x + dirx[i];
            int c = y + diry[i];
            if (!dfs(r, c, m, n, visit, grid)) {
                isClosed = false;
            }
        }

        return isClosed;
    }


    int closedIsland(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();

        int cnt = 0;
        vector<vector<bool> > vis(r, vector<bool>(c));

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                // it the element is a land (0)  and is not visited
                if(grid[i][j] == 0 && !vis[i][j]){
                    if(dfs(i,j,r,c,vis, grid)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;

    }
};