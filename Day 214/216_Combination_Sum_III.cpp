class Solution {
public:
    vector<vector<int>> res;
    void solve(int start,  int n, vector<int> &tmp, int k){
        if(n < 0) return ;
        if(tmp.size() == k && n == 0) res.push_back(tmp);
        for(int i = start; i<=n; i++){
            if(i<=9){
            tmp.push_back(i);
            solve(i+1,n-i,tmp,k);
            tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        solve(1,n,tmp,k);
        return res;
    }
};