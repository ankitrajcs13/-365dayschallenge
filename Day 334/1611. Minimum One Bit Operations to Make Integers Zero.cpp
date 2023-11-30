
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n==0) return 0;//base case
        int k=floor(log2(n));
        int numOp=(1<<(k+1))-1;
        return numOp-minimumOneBitOperations(n^(1<<k));
    }
};