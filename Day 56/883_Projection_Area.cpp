class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sum  = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]!=0) sum++;
            }
        }
        int a = 0;
        while(a<grid.size()){
            int maxi = INT_MIN;
            for(int i=0;i<grid.size();i++){
                maxi=max(maxi,grid[i][a]);
            }
            maxi!=INT_MIN?sum+=maxi:sum+=0;
            a++;
        }
        int b = 0;
        while(b<grid.size()){
            int maxi=INT_MIN;
            for(int i=0;i<grid.size();i++){
                maxi=max(maxi,grid[b][i]);
            }
            maxi!=INT_MIN?sum+=maxi:sum+=0;
            b++;
        }
        return sum;
    }
};