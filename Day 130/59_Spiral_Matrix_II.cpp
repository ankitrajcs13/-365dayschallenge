class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n,vector<int>(n));
        int cnt = 1;
        for(int i =0; i< (n+1)/2; i++){
            // for row from left to right
            // row will be constant and we will update the col to move row wise
            for(int j = i; j < n-i; j++){
                res[i][j] = cnt++;
            }
            // for col from top to bottom
            // col will be constant and we will update row from top to bottom
            for(int j = i+1; j< n-i; j++)
                res[j][n-i-1] = cnt++;
            
            // for row from bottom to top
            // row will be constant and we will update col from right to left
            for(int j = n-i-2; j >= i; j--)
                res[n-i-1][j] = cnt++;

            // for col from bottom to top
            // col will be constant and we will update row from bottom to top
            for(int j = n-i-2; j > i; j--)
                res[j][i] = cnt++;
        }

        return res;



    }
};