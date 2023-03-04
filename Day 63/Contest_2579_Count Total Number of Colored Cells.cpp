class Solution {
public:
    long long coloredCells(int n) {
        long long anKipreSum = pow(n,2);
        long long anKicurSum = pow(n-1,2);
        return anKipreSum+anKicurSum;
    }
};