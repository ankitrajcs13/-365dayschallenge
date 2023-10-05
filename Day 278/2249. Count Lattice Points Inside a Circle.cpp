class Solution {
public:
    int countLatticePoints(vector<vector<int>>& v) { // v is vector of circles.
        int n = v.size();
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int a=v[i][0],b=v[i][1],r=v[i][2];
            for(int x=-r;x<=r;x++){
                for(int y=-r;y<=r;y++){
                    if((x*x)+(y*y)<=(r*r)){
                        s.insert({x+a,y+b});
                    }
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};