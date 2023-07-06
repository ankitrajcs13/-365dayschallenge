class Solution {
public:
    int longestString(int x, int y, int z) {
        int maxi = min(x,y);
        int fl = 0;
        if(x!= y) fl = 1;
        return (2*maxi + fl + z)*2;
        
    }
};