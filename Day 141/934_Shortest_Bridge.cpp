class Solution {
public:
    vector<pair<int,int>> first,second;
    
    void mark(int i,int j, int no, vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1) return;
        grid[i][j]=no;

        if(no==2) first.push_back({i,j});
        else second.push_back({i,j});

        mark(i+1,j,no,grid);
        mark(i-1,j,no,grid);
        mark(i,j+1,no,grid);
        mark(i,j-1,no,grid);
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int count=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1){
                mark(i,j,count,grid);
                count++;}
            }
        }
        int ans=1000000;
        for(int i=0;i<first.size();i++)
            for(int j=0;j<second.size();j++)
                ans=min(abs(first[i].first-second[j].first)+abs(first[i].second-second[j].second)-1,ans);
        return ans;
    }
};