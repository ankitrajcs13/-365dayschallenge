class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n1 = word1.length();
        int n2 = word2.length();

        int i = 0, j = 0;
        int n = 0;
        if(n1< n2) n = n1;
        else n = n2;
        while(n){
            res += word1[i++];
            res+= word2[j++];
            n--;
        }
        while(i < n1){
            res+= word1[i++];
        }
        while(j < n2)
            res+= word2[j++];
        return res;

    }
};