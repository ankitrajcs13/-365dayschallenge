class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        vector<pair<int,int>>tmp;
        tmp.push_back({x,y});
        for(int i = 0; i<path.size(); i++){
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else if(path[i] == 'W') x--;
            tmp.push_back({x,y});
        }
        set<pair<int,int>>st(tmp.begin(),tmp.end());
        if(st.size() == tmp.size()) return false;
        return true;
    }
};