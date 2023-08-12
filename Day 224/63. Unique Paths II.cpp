class Solution {
public:
    int mazeObstaclesUtil(int i, int j, vector<vector<int> > &maze, vector<vector<int>> &dp) {
      if(i<0 || j<0 || maze[i][j]== 1) return 0; 
      if(i==0 && j == 0) return 1;
      if(dp[i][j]!=-1) return dp[i][j];
        
      int left = mazeObstaclesUtil(i,j-1,maze,dp);
      int up = mazeObstaclesUtil(i-1,j,maze,dp);
      
      return dp[i][j] = up+left;
  
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int> > dp(n,vector<int>(m,-1));
        return mazeObstaclesUtil(n-1,m-1,obstacleGrid,dp);
    }
};