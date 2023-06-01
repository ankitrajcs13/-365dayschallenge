class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 || grid[grid.size() - 1][grid[0].size() - 1] == 1) {
            return -1;
        }
        
        int n = grid.size();
        vector<int> dx = {-1, 0, 1};
        vector<int> dy = {-1, 0, 1};
        
        queue<vector<int>> queue;
        queue.push({0, 0, 1});
        grid[0][0] = 1;
        
        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int x = curr[0];
            int y = curr[1];
            int steps = curr[2];
            
            if (x == n - 1 && y == n - 1) {
                return steps;
            }
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int nx = x + dx[i];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        queue.push({nx, ny, steps + 1});
                        // to update the visited grids
                        grid[nx][ny] = 1;
                    }
                }
            }
        }
        
        return -1;

    }
};