class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx-sx);
        int y = abs(fy-sy);
        int tot = max(x,y);
        if( tot > t || (tot == 0 && t == 1))  return false;
        return true;
    }
};