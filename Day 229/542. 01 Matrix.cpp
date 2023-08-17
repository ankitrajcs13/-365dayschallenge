class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        vector<vector<int>> dis(n,vector<int>(m,0));

        queue<pair<pair<int,int> ,int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        // BFS
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            dis[row][col] = step;
            q.pop();

            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                // valid
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] == -1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},step+1});
                }
            }

        }
        return dis;
    }
};