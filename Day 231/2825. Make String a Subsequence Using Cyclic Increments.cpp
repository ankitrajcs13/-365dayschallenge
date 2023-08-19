class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // edge case
        if(str2.length() > str1.length()) return false;
        
        int ankiFl = 0;
        for(int i = 0; i<str1.length(); i++){
            if(str1[i] == str2[ankiFl]) ankiFl++;
            else if( (str1[i] -'a' +1) %26 + 'a' == str2[ankiFl]) ankiFl++;
        }
        
        if(ankiFl == str2.length()) return true;
        return false;
    }
    while(i<n1 && j<n2){
        if(s1[i] == s2[j]) j++;
        else{
            if(s1[i] != 'z') s1[i]++;
            else s1[i]= 'a';
            if(s1[i] == s2[j]) j++;
        }
        i++;
    }
    }
};