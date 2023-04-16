class Solution {
public:
    int solve(int n){
        if(n == 0) return 1;
        int  a = n;
        int cnt = 0;
        while(a != 0){
            int dig = a % 10;
            a = a /10;
            cnt++;
        }
        if(n<0) return cnt+1;
        return cnt;

    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        // if(m == 1) return {1};
        int n = grid[0].size();
        vector<int> ans;
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<m; j++){
                int tmp = solve(grid[j][i]);
                cnt = max(cnt,tmp);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};