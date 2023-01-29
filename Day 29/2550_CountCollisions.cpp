class Solution {
public:
    // to solve the power 
    int psol(long long a, unsigned int b, int p){
        int pres = 1;
        
        a = a% p;
        if(a == 0)  return 0;
        while(b>0){
            if(b&1)
                pres = (pres*a)%p;
            // to divide: b = b/2;
            b = b>>1;
            a = (a*a) % p;
        }
        return pres;
    }
    
    int monkeyMove(int n) {
        //int res = pow(2,n);
        
        // modding the answer, since it can be very large
        //res = res % 1000000007;
        
        int res = psol(2,n,1000000007);
        
        // then remove the clocwise and anticlockwise possible ways to move the monkeys move together
        res -= 2;
        
        // edge case
        if(res <0) //if ans become negative, then add 10^9+7 to it
            res += 1000000007;
        
        return res;
    }
};