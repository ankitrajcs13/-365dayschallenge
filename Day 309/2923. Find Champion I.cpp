class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int sz = grid.size();
        int ankiRes = -1;
        for(int i = 0; i<sz; i++){
            bool ankiFl = true;
            for(int j = 0; j<sz;j++){
                if(i!=j && grid[j][i] == 1){
                    ankiFl = false;
                    break;
                }
            }
            if(ankiFl) ankiRes = i;
        }
        return ankiRes;
    }
};