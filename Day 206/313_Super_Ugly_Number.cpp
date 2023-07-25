class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1)  return 1;
        
        int k = primes.size();
        vector<int> idx(k, 0);
        
        int ugly[n];
        // memset(ugly, 0, sizeof(ugly));
        ugly[0] = 1;
        
        for (int i=1; i<n; i++){
            
            long minVal = INT_MAX;
            for (int j=0; j<k; j++){
                minVal = min(minVal, (long)primes[j] * ugly[idx[j]]);
            }
            
            ugly[i] = (int)minVal;
            for (int j=0; j<k; j++){
                if(minVal == (long)primes[j] * ugly[idx[j]]){
                    idx[j]++;
                }
            }
        }
        
        return ugly[n-1];
    }
};