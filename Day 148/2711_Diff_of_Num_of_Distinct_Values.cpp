class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> AnkiRes(m,vector<int>(n,0));
        
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                // now calc top left and bottom right
                // using set
                unordered_set<int> AnkiLeft, AnkiRight;
                for(int i = 0; i<r; i++){
                    if(i < m && c - r + i >= 0){
                        AnkiLeft.insert(grid[i][c-r+i]);
                    }
                }
                for(int i = r+1; i<m; i++){
                    if(i < m && c + i - r < n){
                        AnkiRight.insert(grid[i][c+i-r]);
                    }
                }
                // then store their size in ans array
                AnkiRes[r][c] = abs(static_cast<int>(AnkiRight.size()) -static_cast<int>(AnkiLeft.size()));
            }
        }
        return AnkiRes;
    }
};