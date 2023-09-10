class Solution {
public:
    int countOrders(int n) {
        int mod= 1e9+7;
        if(n==1) return 1;
        long result = 1;
        for(int i = 2; i<=n; i++){
            int spaces = (i*2)-1;
            int curr = (spaces * (spaces+1))/2;
            result = (result * curr) % mod;
        }
        return (int)result;
    }
};