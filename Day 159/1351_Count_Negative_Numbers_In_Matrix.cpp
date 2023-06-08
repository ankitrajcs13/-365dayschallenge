class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto r:grid){
            for(auto c:r){
                if(c < 0) cnt++;
            }
        }
        return cnt;
    }
};