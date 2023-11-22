class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        map<int,vector<int>>mp;

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<mat[i].size(); j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool fl = true;
        vector<int>res;
        for(auto &it:mp){
            
            for(int num:it.second){
                res.push_back(num);
            }
            fl = !fl;
        }
        return res;
    }
};