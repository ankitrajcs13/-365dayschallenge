class Solution {
public:
     bool solve(string &s, int l, int r){
        
        while(l <= r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxlen = INT_MIN;
        int idx = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        idx = i;
                        maxlen = j-i+1;
                    }
                }
                
            }
        }
        return s.substr(idx, maxlen);
    }
};