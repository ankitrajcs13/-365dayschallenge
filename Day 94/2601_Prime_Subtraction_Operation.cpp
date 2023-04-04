class Solution {
public:
    bool is_prime(int n) {
    
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i] >= nums[i+1]){
                int pFact = nums[i] - nums[i+1] + 1;   
                while(!is_prime(pFact)){
                    pFact++;
                }
                nums[i] -= pFact;
                if(nums[i] <= 0){
                    return false;
                }



            }
        }
        return true;


    }
};