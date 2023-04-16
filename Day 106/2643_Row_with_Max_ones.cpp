class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        int AnkiOnes = 0;
        int AnkiRow = 0;
        // traversing to find the number of ones and comparing with previous ans
        for(int i = 0; i<row; i++){
            int AnkiCnt = 0;
            for(int j = 0; j<col; j++){
                // traversing it row wise ;
                if(mat[i][j] == 1) AnkiCnt++;
            }
            if( AnkiCnt > AnkiOnes){
                AnkiOnes = AnkiCnt;
                AnkiRow = i;
            }
        }
        // returning it as a vector
        return {AnkiRow,AnkiOnes};
        
    }
};