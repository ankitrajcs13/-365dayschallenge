class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int anki1 = abs(fx-sx);
        int ank2 = abs(fy-sy);
        int ankiflag = max(anki1,ank2);
        if(ankiflag >t || (ankiflag == 0 && t == 1 )) return false;
        return true;
    }
};