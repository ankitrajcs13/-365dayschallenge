class Solution {
public:
    bool isvow(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' 
        ) return true;
        return false;
    }
    string sortVowels(string s) {
        string v = "";
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(isvow(s[i])){
                v+=s[i];
            }
        }
        sort(v.begin(), v.end());
        int ptr = 0;
        for(int i = 0; i<n; i++){
            if(isvow(s[i])){
                s[i] = v[ptr++];
            }
        }
        return s;
    }
};