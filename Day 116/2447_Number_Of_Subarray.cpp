class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;

        for(int i = 0; i < n; i++)
            if(nums[i] == k) ans++;
        
        for(int i = 0; i < n; i++){
            bool f = false;
            int gcd = nums[i];
            for(int j = i+1; j<n; j++){
                if(nums[j] % k != 0) break;
                gcd = __gcd(gcd,nums[j]);
                if(gcd == k) f = true;
                if(f) ans+=1;

            }
        }
        return ans;

    }
};