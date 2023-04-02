class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int An = s.size();
        int Ankires = 0;
        int Acn1 = 0, Acn2 = 0;
        for(int i = 0; i<An; i++){
            int k = i;
            int Acn1 = 0, Acn2 = 0;
            for(; k<An;k++){
                if(s[k] == '1') break;
                if(s[k] == '0')Acn1++;
            }
            int t = k;
            for(; t<An; t++){
                if(s[t] == '1') Acn2++;
                if(s[t] == '0') break;
                // store the ans if we found the same number of zeros and ones
                if(Acn1== Acn2) 
                    Ankires = max(Ankires, t-i+1);
            }
            
        }
        return Ankires;
    }
};