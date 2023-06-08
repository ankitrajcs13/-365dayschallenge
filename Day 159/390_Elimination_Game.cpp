class Solution {
public:

    int leftToRight(int n)
    {
        if(n==1) return 1;
        return 2*rightToLeft(n/2);
    }
    int rightToLeft(int n)
    {
        if(n==1) return 1;

        if(n%2) return 2*leftToRight(n/2);
        else return 2*leftToRight(n/2)-1;
    }
    int lastRemaining(int n) {
        return leftToRight(n);
    }
};