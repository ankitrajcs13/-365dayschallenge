int t[101][27][101][101]; //It is allocated in Heap
class Solution {
public:
    //int t[101][27][101][101]; //It will allocated in Stack and will give stack overflow
    int solve(string &s, int i, int prev, int freq, int k ){
        if(k < 0)
            return INT_MAX;
        
        if(i >= s.length())
            return 0;
        
        if(t[i][prev][freq][k] != -1) {
            return t[i][prev][freq][k];
        }
        
        int delete_i = solve(s, i+1, prev, freq, k-1);
        
        int keep_i   = 0;
        
        if(s[i] - 'a' == prev) {
             int one_more_added = 0;
             if(freq == 1 || freq == 9 || freq == 99) {
                 one_more_added = 1;
             }
            keep_i = one_more_added + solve(s, i+1, prev, freq+1, k);
        } else {
            keep_i = 1 + solve(s, i+1, s[i]-'a', 1, k);
        }
        
        return t[i][prev][freq][k] = min(delete_i, keep_i);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0, k);
    }
};