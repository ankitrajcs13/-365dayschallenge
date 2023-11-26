class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int result = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 1 && i > 0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
            vector<int>currRow = matrix[i];
            sort(begin(currRow), end(currRow), greater<int>());
            for(int col = 0; col < m; col++) {
                int base   = (col+1); //iske peeche k columns me >= currRow[col] to hoga hi 1s
                int height = currRow[col];
                
                result = max(result, base*height);
            }
        }
    return result;
    }
};