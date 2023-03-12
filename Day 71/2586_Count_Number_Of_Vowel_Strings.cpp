class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        
        int anki_Res = 0;
        for(int i = left; i<=right; i++){
            int ns = words[i].size()-1;
            if((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u')&&(
            words[i][ns] == 'a' || words[i][ns] == 'e'|| words[i][ns] == 'i' || words[i][ns] == 'o' || words[i][ns] == 'u')) anki_Res++;
            
        }
        return anki_Res;
    }
};