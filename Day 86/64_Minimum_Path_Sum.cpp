class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 1; i<m; i++) 
            grid[i][0] += grid[i-1][0];

        for(int i = 1; i<n; i++) 
            grid[0][i] += grid[0][i-1];


        // updating the minimum distance to reach that positon
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++) 
            grid[i][j] += min(grid[i-1][j] , grid[i][j-1]);
        }

        // now we have the minimum distance present at the last positon of grid
        return grid[m-1][n-1];


    }
};