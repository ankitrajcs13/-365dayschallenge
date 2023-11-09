class Solution {
public:
    int countHomogenous(string s) {
       int len = 0;
       int n = s.size();
       int ans = 0, mod = 1e9+7;
       for(int i = 0; i<n; i++){
           if(i == 0)len++;
           else if(s[i] == s[i-1]) len++;
           else len = 1;
           (ans += len);
           ans%=mod;
       } 
       return ans;
    }
};