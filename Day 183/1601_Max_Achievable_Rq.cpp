class Solution {
public:
    void solve(int idx, int ud, vector<vector<int>> &rq, vector<int> &v, int &res){
        if(idx == rq.size()){
            bool fl = true;
            for(auto it:v){
                if(it!= 0){
                    fl = false;
                }
            }
            if(fl) res = max(res,ud);
            return ;
        }

        int x = rq[idx][0];// from
        int y = rq[idx][1];// to

        // fullfilling the request
        v[x] -=1;
        v[y] +=1;
        solve(idx+1,ud+1,rq,v,res);
        // backtracking
        v[x] +=1;
        v[y] -=1;
        solve(idx+1,ud,rq,v,res);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> bck(n,0);
        int res = 0;
        solve(0,0,requests,bck,res);
        return res;
    }
};