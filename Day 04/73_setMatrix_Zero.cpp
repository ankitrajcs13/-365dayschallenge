class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i<row; i++){
            for(int j = 0;j< col; j++){
                if(matrix[i][j] == 0){
                    // then replace all the corresponding rows and columns to -1
                    int index = i-1;
                    while(index >=0){
                        if(matrix[index][j] !=0)
                            matrix[index][j] = -1;
                        index--;    
                    }
                    index = i+1;
                    while(index<row){
                        if(matrix[index][j] !=0)
                            matrix[index][j] = -1;
                        index++; 
                    }

                    index = j-1;
                    while(index>=0){
                        if(matrix[i][index] !=0)
                            matrix[i][index] = -1;
                        index--; 
                    }
                    index = j+1;
                    while(index<col){
                        if(matrix[i][index] !=0)
                            matrix[i][index] = -1;
                        index++; 
                    }

                }
            }
        }
        // Now we will traverse the matrix again and replace the -1 element to 0
        for(int i = 0; i<row; i++){
            for(int j = 0;j< col; j++){
                if(matrix[i][j] <=0){
                    matrix[i][j] = 0;
                }
            }
        }
        //return matrix;
    }
};

// TC- O((N*M)*(N + M)). O(N*M) 
// SC = O(1)

// 2nd Approach - Optimised using two dummy arrays 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        vector<int> d1(row,-1), d2(col,-1);
        // we are putting the 0 in our dummy areas of the index where we found 0 in matrix
        for(int i = 0; i<row; i++){
            for(int j = 0;j< col; j++){
                if(matrix[i][j] ==0){
                   d1[i]= 0;
                    d2[j] = 0;
                }
            }
        }

        for(int i = 0; i<row; i++){
            for(int j = 0;j< col; j++){
                if(d1[i] == 0 || d2[j] == 0)
                matrix[i][j] = 0;
            }
        }

    }

};

// TC: O(N*M + N*M)
//SC: O(N)

//3rd Approach - Better optimised with constant space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        int cols = 1;
        
        for(int i = 0; i<row; i++){
            // to check if 0 is present in the 0th column or not
            if(matrix[i][0] ==0) cols = 0;
            for(int j = 1;j< col; j++){
                // we are using first row and first column as dummy arrays
                if(matrix[i][j] ==0){
                   matrix[i][0] = 0;
                   matrix[0][j] = 0;
                }
            }
        }
        //traversing in the reverse direction and
        //checking if the row or col has 0 or not
        //and setting values of matrix accordingly.

        for(int i = row-1; i>=0; i--){
            for(int j = col-1;j>=1; j--){
                if(matrix[i][0] == 0|| matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(cols == 0)
                matrix[i][0] = 0;
        }

    }

};
// TC:  O(2*(N*M))
// SC: O(1)