class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = matrix.size();
        int c = matrix[0].size();
        int total = r*c;
        int stRow = 0, stCol = 0, enRow = r-1, enCol = c-1, count = 0;
        while(count <total){
            // for the first row
            for(int i = stCol; i<=enCol && count < total; i++){
                ans.push_back(matrix[stRow][i]);
                count++;
            }
            stRow++;
            // for the last col
            for(int i = stRow; i<=enRow && count < total; i++){
                ans.push_back(matrix[i][enCol]);
                count++;
            }
            enCol--;

            // for the last row
            for(int i = enCol; i>=stCol && count < total; i--){
                ans.push_back(matrix[enRow][i]);
                count++;
            }
            enRow--;

            // for printing the first col
            for(int i = enRow; i>= stRow && count < total; i--){
                ans.push_back(matrix[i][stCol]);
                count++;
            }
            stCol++;
            
            
        }
        return ans;
    }
};