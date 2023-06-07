class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int res = 0;
        while(a | b | c){
            int fst = a & 1;
            int scn = b & 1;
            int thi = c & 1;
            if ( (fst|scn) != thi){ // it means we have to flip the bits
                if( fst & scn){ // it means that we have to flip both the bits 
                    res += 2;
                }
                else res += 1;
            }
            a >>=1;
            b >>=1;
            c >>=1;
        }
        return res;

    }
};

////easy