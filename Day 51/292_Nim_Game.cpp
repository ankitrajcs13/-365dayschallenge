class Solution {
public:
    bool canWinNim(int n) {
        // we can see that if we have n - a multiple of 4 then we are loosing the game

        if(n % 4 == 0) return false;
        else return true;
    }
};