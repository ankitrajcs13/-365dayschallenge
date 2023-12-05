class Solution {
public:
    int numberOfMatches(int n) {
        int i = n;
        int ans = 0;
        while(n>1){
            if(n%2 == 0){
                n = n/2;
                ans+=n;
            }
            else{
                ans += (n-1)/2;
                n = ((n-1)/2) + 1;
            }
        }
        return ans;
    }
};