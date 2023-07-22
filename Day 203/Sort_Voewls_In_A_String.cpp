class Solution {
public:
    string sortVowels(string s) {
        int ankin = s.length();
        string res = "";
        for(int i = 0; i<ankin; i++){
            if(s[i]== 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i]== 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                res+=s[i];
            }
        }
        sort(res.begin(), res.end());
        int tmp = 0;
        for(int i = 0; i<ankin; i++){
            if(s[i]== 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i]== 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
               s[i] = res[tmp];
                tmp++;
            }
        }
        return s;
        
    }
};