class Solution {
public:
    
    bool Anki(int n){
        if(n <= 1) return false;
        
        for(int i = 2; i * i<=n; i++){
            if(n%i == 0) return false;
        }
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        int Myres = 0;
        for(int i = 0; i<nums.size(); i++){
            
            if(isPrime(nums[i][i] )) Myres = max(Myres, nums[i][i]);
            
            if(isPrime(nums[i][nums.size()-i-1])) Myres = max(Myres, nums[i][nums.size()-i-1]);
            
        }
        return Myres;
    }
};