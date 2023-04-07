class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        queue<pair<int,int> > q;

        int m = grid.size();
        int n = grid[0].size();
        // take visited array
        vector<vector<int>> vis(m, vector<int> (n,0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1 ){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // apply bfs traversal
        while(!q.empty()){
            int row = q.front(). first;
            int col = q.front(). second;
            q.pop();

            // now traverse to all the 4 directions if possible
            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow <m && ncol >=0 && 
                ncol <n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){            
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;

                } 
            }
        }
            int cnt = 0;
            for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    cnt++;
                
                }
            }
         return cnt;




    }
};