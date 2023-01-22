class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans = n;
        while(!(ans % n == 0 && ans % 2 == 0))
            ans++;
        return ans;
        
    }
};

// 2nd approach

class Solution {
public:
    int smallestEvenMultiple(int n) {
        // if it is odd then ans will be n * 2
        if(n % 2 != 0)
            return n * 2;
        // else input will be the ans
        else
            return n;
        
    }
};