class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = n/2; i>=1; i--){
            if(n % i == 0){
                // after rotating the string we are checking
                if(s.substr(0,n-i) == s.substr(i))
                    return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for(int i = 1; i<=n/2; i++){
            if(n%i == 0){
                int tm = n/i;
                string st = s.substr(0,i);
                string nst = "";
                while(tm--){
                    nst += st;
                }
                if(nst == s) return true;
            }
        }
        return false;
    }
};