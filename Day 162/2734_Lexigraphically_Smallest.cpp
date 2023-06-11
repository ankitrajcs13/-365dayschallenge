class Solution {
public:
    string smallestString(string s) {
        int ankiS = s.length();
        
        // check the occurence of a in the string
        int cnt = 0;
        while(cnt < ankiS && s[cnt] == 'a') cnt++;
        
        if(cnt == ankiS){
            s[ankiS-1] = 'z';
            return s;
        }
        
        while(cnt < ankiS){
            if(s[cnt] != 'a'){
                s[cnt] = s[cnt]-1;
            }
            else break;
            cnt++;
        }
        
        
        return s;
    }
};