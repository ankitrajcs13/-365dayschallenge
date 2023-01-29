class Solution {
public:
    int distinctIntegers(int n) {
        int dans = n;
        // base case
        if(dans ==1 )
            return 1;
        else// since n can have (n-1) distinct numbers which gives remainder 1
            return dans-1;
        
    }
};