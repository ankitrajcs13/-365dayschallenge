class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& mat ){
        queue<pair<int,int>>q;
        int n = mat.size(), m = mat[0].size();
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        q.push({row,col});
        while(!q.empty()){
            int rrow = q.front().first;
            int ccol = q.front().second;    
            q.pop();
            mat[rrow][ccol] = '1';
            for(int i = 0; i<4; i++){
                int nrow = rrow + drow[i];
                int ncol = ccol + dcol[i];
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m && 
                 mat[nrow][ncol] == 'O'){
                    mat[nrow][ncol] = '1';
                    q.push({nrow,ncol});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        // first row and last row
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O'){
                bfs(0,j,board);
            }
            if(board[n-1][j] == 'O'){
                bfs(n-1,j,board);
            }
        }
        // first col and last col
        for(int i = 0; i<n; i++){
            if(board[i][0] == 'O')
                bfs(i,0,board);
            if(board[i][m-1] == 'O')
                bfs(i,m-1,board);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};