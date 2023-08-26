class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int ini){
        if(image[sr][sc] != color) image[sr][sc] = color;
        
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        int n = image.size(), m = image[0].size();
        for(int i = 0; i<4; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nr < n && nc >=0 && nc < m && ini == image[nr][nc] && 
             image[nr][nc] != color){
                dfs(image,nr,nc,color,ini);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ini = image[sr][sc];
        dfs(image,sr,sc,color,ini);
        return image;
    }
};