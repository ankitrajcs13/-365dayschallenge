class Solution {
public:
    long long minimumCost(string s) {
        int Ankilen = s.length();
        long long AnkiRes = 0;
        
        for(int i = 0; i< Ankilen-1; i++){
            if(s[i] != s[i+1]) {
                // sliding window
                AnkiRes += min(i+1,Ankilen-i-1);
                // as per the condition given in the question
            }
        }
        return AnkiRes;
    }
};