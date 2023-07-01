class Solution {
public:
    void bckTrack(vector<int>& cookies, int k, int ind, vector<int>& cnt,int &res){
        // base case
        if(ind == cookies.size()){
            // calculate unfair value

            int sum = INT_MIN;
            for(int i = 0; i<k; i++){
                sum = max(sum, cnt[i]);
            }
            res = min(res,sum);
            return;
        }

        for(int i = 0; i<k; i++){
            cnt[i]+= cookies[ind];
            bckTrack(cookies,k,ind+1,cnt,res);
            cnt[i]-= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> cnt(k,0);
        int res = INT_MAX;
        bckTrack(cookies,k,0,cnt,res);
        return res;
    }
};