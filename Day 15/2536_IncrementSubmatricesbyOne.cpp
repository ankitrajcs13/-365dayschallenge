class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> solve(n, vector<int>(n, 0));
        // creating a new vector to store the position where we have to update in the matrix.
        // As it will reduce the time complexity by using extra space
    for (auto it : queries) {
        int r1 = it[0], c1 = it[1], r2 = it[2], c2 = it[3];
        solve[r1][c1]++;
        if (r2 + 1 < n && c2 + 1 < n) 
            solve[r2 + 1][c2 + 1]++;
        if (r2 + 1 < n) 
            solve[r2 + 1][c1]--;
        if (c2 + 1 < n) 
            solve[r1][c2 + 1]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) 
                solve[i][j] += solve[i - 1][j];
            if (j > 0) 
                solve[i][j] += solve[i][j - 1];
            if (i > 0 && j > 0) 
                solve[i][j] -= solve[i - 1][j - 1];
            mat[i][j] += solve[i][j];
        }
    }
    return mat;
    }
};