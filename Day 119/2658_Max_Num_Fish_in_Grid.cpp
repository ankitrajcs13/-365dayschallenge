class Solution {
public:
    
    int AnkiSolve(int i, int j, vector<vector<int> > &grid){
        queue<pair<int,int>> myQ;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        
        vis[i][j] = 1;
        myQ.push({i,j});
        int sum = 0; 
        int drow[] = {-1,0,1,0,-1};
        int maxi = INT_MIN;
        while(!myQ.empty()){
            int r = myQ.front().first;
            int c = myQ.front().second;
            myQ.pop();
            
            sum+= grid[r][c];
            for(int i = 0; i<4; i++){
                int nR = r + drow[i];
                int nC = c + drow[i+1];
                
                if(nR >=0 && nR < n && nC >= 0 && nC < m && grid[nR][nC] != 0 && !vis[nR][nC]){
                    myQ.push({nR,nC});
                    vis[nR][nC] = 1;
                }
            }
        }
        return sum;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int Ankires = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] > 0)
                    Ankires = max(Ankires, AnkiSolve(i,j,grid));
            }
        }
        return Ankires;
        
        
    }
};