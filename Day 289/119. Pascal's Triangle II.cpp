class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex+1;
        vector<vector<int>> res(numRows);
        for(int i = 0; i<numRows; i++){
            // for every ith row of 2d vector create a row of i+1 size with value 1
            res[i] = vector<int>(i+1,1);
            for(int j = 1; j<i; j++){ // it will maintain that first n last cell will be 1
            // and if it has more than two elements
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }
        return res[rowIndex];
    }
};