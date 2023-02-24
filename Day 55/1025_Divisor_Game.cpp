class Solution {
public:
    bool divisorGame(int n) {
        
        // we can see that if the n is odd then only alice can win
        if(n% 2 == 0) return true;
        return false;


    }
};