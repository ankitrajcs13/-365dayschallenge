class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.length();
        int an = n-1;
        
        while(an >=0 && num[an] == '0'){
            an--;
        }
        // to get all the trailing zero from string
        
        if(an < 0) return "0";
        
        return num.substr(0,an+1);
        
    }
};