// Using Prefix Sum

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // edge case 
        if(k == 0) return nums;
        int n = nums.size();
        vector<int> res(n,-1);
        vector<long long> preSum(n+1);
        preSum[0] = 1;
        for(int i = 0; i<n; i++){
            preSum[i+1] = nums[i] + preSum[i];
        }
        for(int i = k; i<n-k; i++){
            int l = i-k, r = i+k;
            long long sum = preSum[r+1] - preSum[l];
            int avg = sum/(2*k+1);
            res[i] = avg;
        }
        return res;
    }
};

// Tc- O(N)
// SC- O(N) -> for calculating prefix Sum


// Using Sliding Window
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        int n = nums.size();
        vector<int> res(n,-1);
        if(2*k+1 > n) return res;
        
        long long fSum = 0;
        for(int i = 0; i<2*k+1; i++){
            fSum += nums[i];
        }
        res[k] = fSum/ (2*k+1);
        for(int i = 2*k+1; i<n; i++){
            // adding the value of new element of the window and removing the value of old
            fSum = fSum + nums[i] - nums[i - (2*k+1)];
            res[i-k]= fSum/(2*k+1);
        }
        return res;
    }
};

// Tc - O(N)
// SC - O(1)d