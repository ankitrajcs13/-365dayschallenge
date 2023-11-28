class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int>p;
        int mod = 1e9+7;
        for(int i = 0; i<corridor.size(); i++){
            if(corridor[i] == 'S'){
                p.push_back(i);
            }
        }
        // check for odd length of seats
        if(p.size() % 2 != 0 || p.size() == 0) return 0;

        int prev = p[1];
        long long res = 1;
        for(int i = 2; i<p.size(); i+=2){
            int len = p[i] - prev;
            res = (res * len) % mod;
            prev = p[i+1];
        }
        return res;
    }
};