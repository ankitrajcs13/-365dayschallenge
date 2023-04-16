class Solution {
public:
    int addMinimum(string word) {
     
        // edge case
        if(word.length() == 1) return 2;
        
        
        int Ankicnt = 0;
        if(word[0] == 'b') Ankicnt +=1;
        if(word[0] == 'c') Ankicnt+=2;
        if(word[word.size()-1] == 'a') Ankicnt+=2;
        if(word[word.size()-1] == 'b') Ankicnt+=1;
        
        string s = word;
        for(int i = 0; i<word.length(); i++){
            if ((s[i] == 'a' && s[i+1] =='a') || ( s[i] == 'b' && s[i+1]== 'b') || (s[i] == 'c' && s[i+1] == 'c')) Ankicnt+= 2;
            else if (( s[i] == 'a' && s[i+1] == 'b') || (s[i] == 'b' && s[i+1] =='c') || (s[i] == 'c' && s[i+1] == 'a')) Ankicnt+=0;
            else if ((s[i] =='a' && s[i+1] == 'c') || (s[i] == 'b' && s[i+1] == 'a') || (s[i]== 'c' && s[i+1]== 'b')) Ankicnt+=1;
        }
        return Ankicnt;
        
        
        
        
        
    }
};