class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int ankiArr[26][2] = {0};
        for(int i = 0; i<s1.size(); i++){
            if(i%2 == 0){
                ankiArr[s1[i] - 'a'][0]++;
                ankiArr[s2[i] - 'a'][0]--;
            }
            else{
                ankiArr[s1[i] - 'a'][1]++;
                ankiArr[s2[i] - 'a'][1]--;
            }
            
        }
        for(int ankiI = 0; ankiI<26; ankiI++){
            for(int ankiJ = 0; ankiJ<2; ankiJ++){
                if(ankiArr[ankiI][ankiJ] != 0)return false;
            }
        }
        return true;
    }
};