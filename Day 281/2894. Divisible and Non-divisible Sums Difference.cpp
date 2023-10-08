class Solution {
public:
    int differenceOfSums(int n, int m) {
        int anki1 = 0, anki2;
        for(int i = 1; i<=n; i++){
            if(i% m != 0) anki1+=i;
        }
        for(int i = 1; i<=n; i++){
            if(i % m == 0) anki2+=i;
        }
        
        return anki1-anki2;
    }
};