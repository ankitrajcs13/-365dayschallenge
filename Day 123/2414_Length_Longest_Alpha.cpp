class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1, tmp = 1;
        // if(s.length() == 1) return 1;
        for(int i = 1; i<=s.length(); i++){
            if( s[i] - s[i-1] == 1 ) {
                tmp++;
                ans = max(ans,tmp);
            }
            else tmp = 1;
        }
        return ans;


    }
};