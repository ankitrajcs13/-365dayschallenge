class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        // find the minimum and maximum element from the array
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < mini)
                mini = nums[i];
            if(nums[i] > maxi)
                maxi = nums[i];
        }
        // then find their gcd
        int ans = gcd(mini,maxi);
        return ans;
        
    }
};
// 2nd approach -> without gcd function

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = 0, mini = 1001;
       for (auto i: nums)
       {
           mini = min(mini, i);
           maxi = max(maxi, i);
       }
       
       for (int i = mini; i >= 1; i--)
       {
           if (mini % i == 0 && maxi % i == 0)
               return i;
       }
       return -1;
    }
};