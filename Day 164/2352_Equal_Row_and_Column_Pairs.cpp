class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> row2cnt;
        for(int i=0;i<n;i++)
            row2cnt[ grid[i] ]++;
        
        int cnt = 0;
        vector<int> col(n);
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++)
                col[i] = grid[i][j];
            cnt += row2cnt[ col ];
        }

        return cnt;
    }
};

//2nd approach

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                bool match = true;
                for (int i = 0; i < n; ++i) {
                    if (grid[r][i] != grid[i][c]) {
                        match = false;
                        break;
                    }
                }
                if(match) res += 1;
            }
        }
        
        return res;
    }
};