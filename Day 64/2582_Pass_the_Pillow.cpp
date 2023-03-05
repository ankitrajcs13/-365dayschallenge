class Solution {
public:
    int passThePillow(int n, int time) {
     
        int anki_tmp = 1;
       bool ank_rev = false;
        int s = 0;
        
        for(int i = 1; i<=time; i++){
            if(anki_tmp == n)
                ank_rev = true;
            else if (anki_tmp == 1)
                ank_rev = false;
            
            if(ank_rev)
                anki_tmp--;
            else
                anki_tmp++;
            
        }
        return anki_tmp;
        
        
    }
};