class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        int tNum = n;
        int cnt = 0;
        while (tNum > 0) {
            cnt++;
            tNum /= 10;
        }
        if(n>9){
            while(n>0){
                int digit = n % 10;
                n = n/10;
                if(cnt % 2 == 0){
                    // even size
                    ans -=digit;
                }
                else{
                    ans+=digit;
                }
                cnt--;
            }
        }
        else{
            ans+=n;
        }
        return ans;
    }
};
