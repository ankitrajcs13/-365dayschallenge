class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>deg;
        for(auto it: paths){
            string node = it[0];
            deg[node]++;
        }
        for(auto it:paths){
            if(deg[it[1]] == 0) return it[1];
        }
        return "";
    }
};