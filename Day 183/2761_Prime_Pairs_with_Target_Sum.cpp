class Solution {
public:
    vector<int> AnkiisPrime(int n){
        vector<bool> isPrime(n+1,true);
        vector<int> Ankiprime;
        
        isPrime[0] = isPrime[1] = false;
        
        for(int i =2 ;i*i <=n; i++){
            if(isPrime[i]){
                for(int j = i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i = 2; i<=n; i++){
            if(isPrime[i]){
                Ankiprime.push_back(i);
            }
        }
        return Ankiprime;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> totPrimes = AnkiisPrime(n);
        vector<vector<int>> ankires;
        
        for(int i = 0; i< totPrimes.size(); i++){
            int x = totPrimes[i], y = n-x;
            
            if(y >=x && binary_search(totPrimes.begin(), totPrimes.end(), y))
                ankires.push_back({x,y});
            
        }
        return ankires;
        
        
    }
};